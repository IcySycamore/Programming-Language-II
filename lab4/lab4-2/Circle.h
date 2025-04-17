#pragma once
#include "Shape.h"
class Circle :
	public TwoDimensionalShape
{
private:
	double radius = 0;
	Point2D centerOfCircle{ 0 , 0 };
protected:
public:
	Circle(Point2D c, double r) : centerOfCircle(c) {
		tag.push_back("Circle");
		setRadius(r);
	}//Ô²ÐÄ£¬°ë¾¶
	~Circle() {}
	void setRadius(double r) { radius = std::abs(r); }
	void setCenter(Point2D p) { centerOfCircle = p; }
	double getArea()const override { return PI * radius * radius; }
	void print()const {
		std::cout
			<< "\nradius\t" << radius
			<< "\ncenterOfCircle\t" << centerOfCircle
			<< "\narea\t" << getArea();
	}

};

