#pragma once
#include "Shape.h"
class Rectangle :
	protected Shape
{
protected:
	Point2D lefttop;
	Point2D  rightbottom;
	double long_side;
	double short_side;
	double delta_x;
	double delta_y;
public:
	Rectangle(Point2D lt, Point2D rb) :lefttop(lt), rightbottom(rb) { update_info(); }
	~Rectangle() {}
	double area()const { return long_side * short_side; }
	void print()const {
		std::cout
			<< "\nleft_top\t" << lefttop
			<< "\nright_bottom\t" << rightbottom
			<< "\nlong_side\t" << long_side
			<< "\nshort_side\t" << short_side;
	}
	void update_info() {
		delta_x = std::abs(lefttop.x - rightbottom.x);
		delta_y = std::abs(lefttop.y - rightbottom.y);
		long_side = std::max(delta_x, delta_y);
		short_side = std::min(delta_x, delta_y);
	}//更新数据
	void setLT(Point2D a) { lefttop = a; update_info(); }
	void setRB(Point2D a) { rightbottom = a; update_info(); }
};

