#pragma once
#include "Rectangle.h"
#include "Circle.h" // Add this include to make Circle known

class Square :
	public Rectangle
{
	friend class Circle;
public:
	Square(Point2D a, double len, std::string choose = "lt") : Rectangle(Point2D{ 0, 0 }, Point2D{ 0, 0 }) {
		tag.erase(tag.end() - 1);
		tag.push_back("Square");
		if (choose == "lt") {
			setLT(a);
			setRB(Point2D{ a.x + len, a.y - len });
		}
		else if (choose == "rb") {
			setLT(Point2D{ a.x - len, a.y + len });
			setRB(a);
		}
		else
			throw(std::invalid_argument("invalid choose"));
		check();
	}//默认点为左上
	~Square() {}
	void check() {
		if (delta_x != delta_y) {
			throw(std::runtime_error("delta_x != delta_y"));
		}
	}
	Circle InnerCircle() {
		check();
		return Circle(lefttop.midPoint(rightbottom), delta_x / 2);
	}
};
