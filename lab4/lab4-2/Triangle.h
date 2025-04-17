#pragma once
#include "Shape.h"
class Triangle :
	public TwoDimensionalShape
{
protected:
	Point2D a;
	Point2D b;
	Point2D c;
	double l_a_b;
	double l_a_c;
	double l_b_c;
public:
	Triangle(Point2D a, Point2D b, Point2D c) :a(a), b(b), c(c) {
		tag.push_back("Triangle");
		update();
		check();
	}

	~Triangle() {}
	void check() const {
		if (l_a_b + l_a_c <= l_b_c)
			throw std::invalid_argument("Triangle is not exist");
	}
	void update() {
		l_a_b = a.distance(b);
		l_a_c = a.distance(c);
		l_b_c = b.distance(c);
	}
	double getArea() const override {
		double perimeter = (l_a_b + l_a_c + l_b_c) / 2;
		return std::sqrt(perimeter * (perimeter - l_a_b) * (perimeter - l_a_c) * (perimeter - l_b_c));
	}
	void print()const {
		std::cout
			<< "A" << a
			<< "B" << b
			<< "C" << c
			<< "area" << getArea();
	}
};

