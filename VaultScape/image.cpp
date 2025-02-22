//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "image.h"

//=============================================================================
// default constructor
//=============================================================================
Image::Image()
{
	initialized = false;            // set true when successfully initialized
	spriteData.width = 2;
	spriteData.height = 2;
	spriteData.x = 0.0;
	spriteData.y = 0.0;
	spriteData.scale = 1.0;
	spriteData.angle = 0.0;
	spriteData.rect.left = 0;       // used to select one frame from multi-frame image
	spriteData.rect.top = 0;
	spriteData.rect.right = spriteData.width;
	spriteData.rect.bottom = spriteData.height;
	spriteData.texture = NULL;      // the sprite texture (picture)
	spriteData.flipHorizontal = false;
	spriteData.flipVertical = false;
	cols = 1;
	textureManager = NULL;
	startFrame = 0;
	endFrame = 0;
	currentFrame = 0;
	frameDelay = 1.0;               // default to 1 second per frame of animation
	animTimer = 0.0;
	visible = true;                 // the image is visible
	loop = true;                    // loop frames
	animComplete = false;
	graphics = NULL;                // link to graphics system
	colorFilter = graphicsNS::WHITE; // WHITE for no change
}

//=============================================================================
// destructor
//=============================================================================
Image::~Image()
{}

//=============================================================================
// Initialize the Image.
// Post: returns true if successful, false if failed
// pointer to Graphics
// width of Image in pixels  (0 = use full texture width)
// height of Image in pixels (0 = use full texture height)
// number of columns in texture (1 to n) (0 same as 1)
// pointer to TextureManager
//=============================================================================
bool Image::initialize(Graphics *g, int width, int height, int ncols,
	TextureManager *textureM)
{
	try {
		graphics = g;                               // the graphics object
		textureManager = textureM;                  // pointer to texture object

		spriteData.texture = textureManager->getTexture();
		if (width == 0)
			width = textureManager->getWidth();     // use full width of texture
		spriteData.width = width;
		if (height == 0)
			height = textureManager->getHeight();   // use full height of texture
		spriteData.height = height;
		cols = ncols;
		if (cols == 0)
			cols = 1;                               // if 0 cols use 1

													// configure spriteData.rect to draw currentFrame
		spriteData.rect.left = (currentFrame % cols) * spriteData.width;
		// right edge + 1
		spriteData.rect.right = spriteData.rect.left + spriteData.width;
		spriteData.rect.top = (currentFrame / cols) * spriteData.height;
		// bottom edge + 1
		spriteData.rect.bottom = spriteData.rect.top + spriteData.height;
	}
	catch (...) { return false; }
	initialized = true;                                // successfully initialized
	return true;
}


//=============================================================================
// Draw the image using color as filter
// The color parameter is optional, WHITE is assigned as default in image.h
// Pre : spriteBegin() is called
// Post: spriteEnd() is called
//=============================================================================
void Image::draw(COLOR_ARGB color)
{
	if (!visible || graphics == NULL)
		return;
	// get fresh texture incase onReset() was called
	spriteData.texture = textureManager->getTexture();
	if (color == graphicsNS::FILTER)                     // if draw with filter
		graphics->drawSprite(spriteData, colorFilter);  // use colorFilter
	else
		graphics->drawSprite(spriteData, color);        // use color as filter
}

//=============================================================================
// Draw this image using the specified SpriteData.
//   The current SpriteData.rect is used to select the texture.
// Pre : spriteBegin() is called
// Post: spriteEnd() is called
//=============================================================================
void Image::draw(SpriteData sd, COLOR_ARGB color)
{
	if (!visible || graphics == NULL)
		return;
	sd.rect = spriteData.rect;                  // use this Images rect to select texture
	sd.texture = textureManager->getTexture();  // get fresh texture incase onReset() was called

	if (color == graphicsNS::FILTER)             // if draw with filter
		graphics->drawSprite(sd, colorFilter);  // use colorFilter
	else
		graphics->drawSprite(sd, color);        // use color as filter
}

//=============================================================================
// Draw this image using the specified SpriteData.
//   The current SpriteData.rect is used to select the texture.
// Pre : spriteBegin() is called
// Post: spriteEnd() is called
//=============================================================================
void Image::printText(TextDX text, std::string msg)
{
	if (!visible || graphics == NULL)
		return;
	spriteData.texture = textureManager->getTexture();  // get fresh texture incase onReset() was called

	RECT tempRect;
	int centerX = spriteData.x + spriteData.width / 2 * getScale();;
	int centerY = spriteData.y + spriteData.height / 2 * getScale();;

	int top = spriteData.y;
	int left = spriteData.x;
	int right = centerX + (centerX - spriteData.x);
	int bottom = centerY + (centerY - spriteData.y);
	tempRect.top = top;
	tempRect.left = left;
	tempRect.right = right;
	tempRect.bottom = bottom;
	text.print(msg, tempRect, DT_CENTER|DT_VCENTER);
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Image::update(float frameTime)
{
	if (endFrame - startFrame > 0)          // if animated sprite
	{
		animTimer += frameTime;             // total elapsed time
		if (animTimer > frameDelay)
		{
			animTimer -= frameDelay;
			currentFrame++;
			if (currentFrame < startFrame || currentFrame > endFrame)
			{
				if (loop == true)            // if looping animation
					currentFrame = startFrame;
				else                        // not looping animation
				{
					currentFrame = endFrame;
					animComplete = true;    // animation complete
				}
			}
			setRect();                      // set spriteData.rect
		}
	}
}

//=============================================================================
// Set the current frame of the image
//=============================================================================
void Image::setCurrentFrame(int c)
{
	if (c >= 0)
	{
		currentFrame = c;
		animComplete = false;
		setRect();                          // set spriteData.rect
	}
}

//=============================================================================
//  Set spriteData.rect to draw currentFrame
//=============================================================================
inline void Image::setRect()
{
	// configure spriteData.rect to draw currentFrame
	spriteData.rect.left = (currentFrame % cols) * spriteData.width;
	// right edge + 1
	spriteData.rect.right = spriteData.rect.left + spriteData.width;
	spriteData.rect.top = (currentFrame / cols) * spriteData.height;
	// bottom edge + 1
	spriteData.rect.bottom = spriteData.rect.top + spriteData.height;
}
