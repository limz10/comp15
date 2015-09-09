#include <iostream>
#include "rectangle.h"

using namespace std;

//CONSTRUCTORS
rectangle::rectangle()
{
    width = 1;
    height = 1;
}

rectangle::rectangle(float side)
{
    if (side > 0) {
	width = side;
	height = side;
    }
}

rectangle::rectangle(float w, float h)
{
    if ((w > 0) && (h > 0)) {
	width = w;
	height = h;
    }
}

//GETTERS
float rectangle::getWidth()
{
    return width;
}

float rectangle::getHeight()
{
    return height;
}

// SETTERS
void rectangle::setWidth(float w)
{
    width = w;
}

void rectangle::setHeight(float h)
{
    height = h;
}

// OTHER MEMBER FUNCTIONS
float rectangle::perimeter()
{
    return 2 * (width + height);
}

float rectangle::area()
{
    return width * height;
}

bool rectangle::isSquare()
{
    if (width == height)
	return true;
    else
	return false;
}
