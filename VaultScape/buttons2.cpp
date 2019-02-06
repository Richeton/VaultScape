//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "buttons2.h"

// The primary class should inherit from Button class

Button::Button()
{

}
Button::Button(long t, long l, long b, long r, std::string txt, ButtonNS::ON_CLICK func)
{
	top = t;
	left = l;
	bottom = b;
	right = r;
	function = func;
	this->text = text;
}

Button::Button(Image img, ButtonNS::ON_CLICK func)
{
	left = img.getX();
	right = img.getCenterX() + (img.getCenterX() - img.getX());
	top = img.getY();
	bottom = img.getCenterY() + (img.getCenterY() - img.getY());
	function = func;
}

Button::~Button()
{

}


void Button::update(Image img)
{

	left = img.getX();
	right = img.getCenterX() + (img.getCenterX() - img.getX());
	top = img.getY();
	bottom = img.getCenterY() + (img.getCenterY() - img.getY());
}
