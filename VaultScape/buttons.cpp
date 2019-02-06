#include "buttons.h"

Button::Button()
{
}

Button::Button(Image img, std::string txt) 
{
	buttonImg = img;
	top = buttonImg.getSpriteDataRect().top;
	left = buttonImg.getSpriteDataRect().left;
	right = buttonImg.getSpriteDataRect().right;
	bottom = buttonImg.getSpriteDataRect().bottom;
	overlayedText = txt;
	selectedKeyboard = false;
	selectedMouse = false;
}

Button::Button(int t, int l, int r, int b, std::string txt) 
{
	top = t;
	left = l;
	bottom = b;
	right = r;
	overlayedText = txt;
	selectedKeyboard = false;
	selectedMouse = false;
}