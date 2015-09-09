/*
	Comp 15 HW1
	Mingzhe Li
	Jan 16, 2014
	This program creates two rectangles and reports their areas, 
	perimeters, and whether square or not.
*/

#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
    //creates r1
    rectangle r1;

    //reads width and height of r2
    float w,h;
    cin >> w;
    cin >> h;	

    //creates r2
    rectangle r2(w,h);

    //reports r1
    cout << "r1 has area " << r1.area()
	 << " perimeter " << r1.perimeter() << " and is ";
    if (r1.isSquare())
	cout << "a square" << endl;
    else 
	cout << "not a square" << endl;

    //reports r2
    cout << "r2 has area " << r2.area() 
	 << " perimeter " << r2.perimeter() << " and is ";
    if (r2.isSquare())
	cout << "a square" << endl;
    else 
	cout << "not a square" << endl;

    return 0;
}
