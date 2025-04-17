#pragma once
#include "Shape.h"  
class Cylinder : public ThreeDimensionalShape {
public:
	Cylinder(double r = 0, double h = 0, Point2D p = { 0, 0 }) :ThreeDimensionalShape() {
		tag.push_back("Cylinder");
		setRadius(r);
		setHeight(h);
		setCenter(p);
	};
	~Cylinder() {};
	double getArea() const override {
		return 2 * PI * radius * height + 2 * PI * radius * radius;
	}
	double getVolume() const override {
		return PI * radius * radius * height;
	}
	void setRadius(double r) { radius = std::abs(r); }
	void setHeight(double h) { height = std::abs(h); }
	void setCenter(Point2D p) { centerOfCylinder = p; }
	void print() const {
		std::cout
			<< "\nradius\t" << radius
			<< "\nheight\t" << height
			<< "\ncenterOfCylinder\t" << centerOfCylinder
			<< "\narea\t" << getArea()
			<< "\nvolume\t" << getVolume();
	}
private:
	double radius = 0;
	double height = 0;
	Point2D centerOfCylinder{ 0, 0 };
};