#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

int main() {
	try {
		// 测试 Circle 类
		std::cout << "=== Circle 测试 ===" << std::endl;
		Circle circle1(Point2D{ 0, 0 }, 5.0);  // 正常半径
		Circle circle2(Point2D{ 0, 0 }, 0);   // 半径为0
		Circle circle3(Point2D{ 0, 0 }, -1);  // 负半径

		std::cout << "Circle1 (半径5) 面积: " << circle1.area() << std::endl;
		std::cout << "Circle2 (半径0) 面积: " << circle2.area() << std::endl;
		std::cout << "Circle3 (半径-1) 面积: " << circle3.area() << std::endl;

		// 测试 Rectangle 类
		std::cout << "\n=== Rectangle 测试 ===" << std::endl;
		Rectangle rect1(Point2D{ 0, 0 }, Point2D{ 4, 6 });
		Rectangle rect2(Point2D{ 0, 0 }, Point2D{ 0, 5 });
		Rectangle rect3(Point2D{ 0, 0 }, Point2D{ -2, 3 });

		std::cout << "Rectangle1 (4x6) 面积: " << rect1.area() << std::endl;
		std::cout << "Rectangle2 (0x5) 面积: " << rect2.area() << std::endl;
		std::cout << "Rectangle3 (2x3) 面积: " << rect3.area() << std::endl;

		// 测试 Square 类
		std::cout << "\n=== Square 测试 ===" << std::endl;
		Square square1(Point2D{ 0, 0 }, 5);
		Square square2(Point2D{ 0, 0 }, 0);
		Square square3(Point2D{ 0, 0 }, -3);

		std::cout << "Square1 (边长5) 面积: " << square1.area() << std::endl;
		std::cout << "Square2 (边长0) 面积: " << square2.area() << std::endl;
		std::cout << "Square3 (边长-3) 面积: " << square3.area() << std::endl;

		// 测试 Triangle 类
		std::cout << "\n=== Triangle 测试 ===" << std::endl;
		Triangle tri1(Point2D{ 0, 0 }, Point2D{ 3, 0 }, Point2D{ 0, 4 });    // 正常三角形
		//Triangle tri2(Point2D{ 0, 0 }, Point2D{ 1, 1 }, Point2D{ 1, 3 });    // 非法三角形
		//Triangle tri3(Point2D{ 0, 0 }, Point2D{ 0, 0 }, Point2D{ 0, 5 });    // 零边长
		Triangle tri4(Point2D{ 0, 0 }, Point2D{ -2, 0 }, Point2D{ 0, 4 });   // 

		std::cout << "Triangle1 (3-4-5) 面积: " << tri1.area() << std::endl;
		//std::cout << "Triangle2 (1-1-3) 面积: " << tri2.area() << std::endl;
		//std::cout << "Triangle3 (0-4-5) 面积: " << tri3.area() << std::endl;
		std::cout << "Triangle4 (2-√20-4) 面积: " << tri4.area() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "捕获到异常: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "捕获到未知异常" << std::endl;
	}

	return 0;
}
