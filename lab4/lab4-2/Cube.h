#pragma once  
#include "Shape.h"  
class Cube : public ThreeDimensionalShape {
public:
	Cube(double s = 0, Point2D p = { 0, 0 }) :ThreeDimensionalShape() {
		tag.push_back("Cube");
		setSide(s);
		setCenter(p);
	};
	~Cube() {};
	double getArea() const override {
		return 6 * sideLength * sideLength;
	}
	double getVolume() const override {
		return sideLength * sideLength * sideLength;
	}
	void setSide(double s) { sideLength = std::abs(s); }
	void setCenter(Point2D p) { centerOfCube = p; }
	void print() const {
		std::cout
			<< "\nsideLength\t" << sideLength
			<< "\ncenterOfCube\t" << centerOfCube
			<< "\narea\t" << getArea()
			<< "\nvolume\t" << getVolume();
	}
private:
	double sideLength;
	Point2D centerOfCube{ 0, 0 };
};