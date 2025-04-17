#pragma once
#include "Shape.h"  
class Sphere : public ThreeDimensionalShape {
public:
	Sphere(double r = 0, Point2D p = { 0, 0 }) :ThreeDimensionalShape() {
		tag.push_back("Sphere");
		setRadius(r);
		setCenter(p);
	};
	~Sphere() {};
	double getArea() const override {
		return 4 * PI * radius * radius;
	}
	double getVolume() const {
		return (4.0 / 3.0) * PI * radius * radius * radius;
	}
	void setRadius(double r) { radius = std::abs(r); }
	void setCenter(Point2D p) { centerOfSphere = p; }
	void print() const {
		std::cout
			<< "\nradius\t" << radius
			<< "\ncenterOfSphere\t" << centerOfSphere
			<< "\narea\t" << getArea()
			<< "\nvolume\t" << getVolume();
	}
private:
	double radius = 0;
	Point2D centerOfSphere{ 0, 0 };
};