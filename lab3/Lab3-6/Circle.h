#pragma once
#include "Shape.h"
constexpr double PI = 3.1415926535897932384626433;
class Circle :
	protected Shape
{
private:
	double radius = 0;
	Point2D centerOfCircle{ 0 , 0 };
protected:
public:
	Circle(Point2D c, double r) : centerOfCircle(c) { setRadius(r); }//Ô²ÐÄ£¬°ë¾¶
	~Circle() {}
	void setRadius(double r) { radius = std::abs(r); }
	void setCenter(Point2D p) { centerOfCircle = p; }
	double area()const { return PI * radius * radius; }
	void print()const {
		std::cout
			<< "\nradius\t" << radius
			<< "\ncenterOfCircle\t" << centerOfCircle
			<< "\narea\t" << area();
	}

};

