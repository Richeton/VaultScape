#ifndef  _BUTTONS_H
#define _BUTTONS_H
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "image.h"
#include "textDX.h"

class GameState;

// The buttons' function is to transition between different game states
// Eg: Main Menu --> Running

namespace ButtonNS
{
	const int BUTTON_WIDTH = 240;
	const int BUTTON_HEIGHT = 72;
	const int BUTTON_NCOLS = 0;
}

class Button
{
private:
	// Details of button
	GameState * nextGameState;
	bool selectedKeyboard;
	bool selectedMouse;
	std::string overlayedText;
	TextDX font;
	Image buttonImg;
	
	int top;
	int bottom;
	int left;
	int right;
	
public:
	Button();
	Button(Image img, std::string text);
	Button(int top, int left, int right, int bottom, std::string text);


	// Get/Set Next State of the Buttons
	void setNextState(GameState * gs) { nextGameState = gs; }
	GameState * getNextState() { return nextGameState; }

	// Get/Set Position of the Button
	void setPos(int newX, int newY) 
	{
		buttonImg.setX(newX);
		buttonImg.setY(newY);
		top = buttonImg.getY();
		left = buttonImg.getX();
		right = buttonImg.getCenterX() + (buttonImg.getCenterX() - buttonImg.getX());
		bottom = buttonImg.getCenterY() + (buttonImg.getCenterY() - buttonImg.getY());
	}

	int getTop() { return top; }
	int getLeft() { return left; }
	int getRight() { return right; }
	int getBottom() { return bottom; }
	
	// Get/Set SelectedKeyboard
	void setSelectedKeyboard(bool b) 
	{
		selectedKeyboard = b;
		if (selectedKeyboard)
			buttonImg.setCurrentFrame(1);
		else
			buttonImg.setCurrentFrame(0);
	}
	bool getSelectedKeyboard() { return selectedKeyboard; }

	// Get/Set SelectedMouse
	void setSelectedMouse(bool b) 
	{ 
		selectedMouse = b; 
		if (selectedMouse)
			buttonImg.setCurrentFrame(1);
		else
			buttonImg.setCurrentFrame(0);
	}
	bool getSelectedMouse() { return selectedMouse; }


	// Get/Set Text
	void setText(std::string t) {overlayedText = t; }
	std::string getText() { return overlayedText; }

	// Get/Set Image
	void setImage(Image i) { buttonImg = i; }
	Image getImage() { return buttonImg; }
	
	// Get/Set Font
	void setFont(TextDX f) { font = f; }
	TextDX getFont() { return font; }


	// Hovered over
	bool mouseOnButton(Input in) 
	{
		int mouseX = in.getMouseX();
		int mouseY = in.getMouseY();

		if (mouseX > left && mouseX < right && mouseY > top && mouseY < bottom)
			return true;
		else
			return false;

	}

	void printText() { buttonImg.printText(font, overlayedText); }
};

#endif