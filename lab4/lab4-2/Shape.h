#pragma once
#include<string>
#include <iostream>
#include <cmath>
#include <exception>
#include<vector>
constexpr double PI = 3.1415926535897932384626433;
struct Point2D
{
	double x;
	double y;
	Point2D midPoint(Point2D a) { return Point2D{ double(a.x + y) / 2,double(a.y + y) / 2 }; }
	double distance(Point2D a) { return std::sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y)); }
	friend std::ostream& operator<<(std::ostream& output, Point2D p);
	friend std::istream& operator>>(std::istream& input, Point2D p);
};
inline std::ostream& operator<<(std::ostream& output, Point2D p) {
	output << "(" << p.x << "," << p.y << ")";
	return output;
}
inline std::istream& operator>>(std::istream& input, Point2D p)
{
	input >> p.x >> p.y;
	return input;
}
static int num_of_shapes = 0;
class Shape
{
protected:
	std::vector<std::string>tag = {};
	std::string id;
	Shape() {}
	~Shape() { num_of_shapes -= 1; }
public:
	void setID() {}
	std::string getID() const { return id; }
	virtual double getArea()const = 0;
	void getTag()const {
		for (std::string str : tag) {
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
};
class TwoDimensionalShape : public Shape {
protected:
	TwoDimensionalShape() : Shape() {
		tag.push_back("TwoDimensionalShape");
	}
	~TwoDimensionalShape() {}
};

class ThreeDimensionalShape : public Shape {
protected:
	ThreeDimensionalShape() : Shape() {
		tag.push_back("ThreeDimensionalShape");
	}
	~ThreeDimensionalShape() {}
	virtual double getVolume() const = 0;
};

