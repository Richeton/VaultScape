//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "image.h"

#ifndef  _BUTTONS_H2
#define _BUTTONS_H2
#define WIN32_LEAN_AND_MEAN


namespace ButtonNS
{
	enum ON_CLICK { START_GAME, EXIT_GAME, RESUME_GAME, MAIN_MENU, UPLOAD, OPTIONS, NONE };
}

class Button
{
private:
	bool selected = false;
	int top;
	int bottom;
	int right;
	int left;
	std::string text;
	bool highlighted = false;

	ButtonNS::ON_CLICK function;


public:

	Button();
	Button(long top, long left, long bottom, long right, std::string text, ButtonNS::ON_CLICK func);
	Button(Image img, ButtonNS::ON_CLICK func);
	~Button();


	ButtonNS::ON_CLICK return_function() { return function; }

	int getLeft() { return left; }
	int getRight() { return right; }
	int getTop() { return top; }
	int getBottom() { return bottom; }
	bool isSelected() { return selected; }
	void setSelected(bool b) { selected = b; }
	void update(Image img);

};


#endif  //_BUTTONS_H