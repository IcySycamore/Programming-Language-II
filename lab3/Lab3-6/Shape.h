#pragma once
#include<string>
#include <iostream>
#include <cmath>
#include <stdexcept>
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

	std::string id;
	enum class shape {};
public:
	Shape() {}
	~Shape() { num_of_shapes -= 1; }
	void setID() {}
	std::string getID() const { return id; }

};

