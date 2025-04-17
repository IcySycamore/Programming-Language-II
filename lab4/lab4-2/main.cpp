#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Cube.h"


int main() {
	try {
		// 测试 Circle 类
		std::cout << "=== Circle 测试 ===" << std::endl;
		Circle circle1(Point2D{ 0, 0 }, 5.0);  // 正常半径
		Circle circle2(Point2D{ 0, 0 }, 0);   // 半径为0
		Circle circle3(Point2D{ 0, 0 }, -1);  // 负半径

		std::cout << "Circle1 (半径5) 面积: " << circle1.getArea() << std::endl;
		std::cout << "Circle2 (半径0) 面积: " << circle2.getArea() << std::endl;
		std::cout << "Circle3 (半径-1) 面积: " << circle3.getArea() << std::endl;

		// 测试 Rectangle 类
		std::cout << "\n=== Rectangle 测试 ===" << std::endl;
		Rectangle rect1(Point2D{ 0, 0 }, Point2D{ 4, 6 });
		Rectangle rect2(Point2D{ 0, 0 }, Point2D{ 0, 5 });
		Rectangle rect3(Point2D{ 0, 0 }, Point2D{ -2, 3 });

		std::cout << "Rectangle1 (4x6) 面积: " << rect1.getArea() << std::endl;
		std::cout << "Rectangle2 (0x5) 面积: " << rect2.getArea() << std::endl;
		std::cout << "Rectangle3 (2x3) 面积: " << rect3.getArea() << std::endl;

		// 测试 Square 类
		std::cout << "\n=== Square 测试 ===" << std::endl;
		Square square1(Point2D{ 0, 0 }, 5);
		Square square2(Point2D{ 0, 0 }, 0);
		Square square3(Point2D{ 0, 0 }, -3);

		std::cout << "Square1 (边长5) 面积: " << square1.getArea() << std::endl;
		std::cout << "Square2 (边长0) 面积: " << square2.getArea() << std::endl;
		std::cout << "Square3 (边长-3) 面积: " << square3.getArea() << std::endl;

		// 测试 Triangle 类
		std::cout << "\n=== Triangle 测试 ===" << std::endl;
		Triangle tri1(Point2D{ 0, 0 }, Point2D{ 3, 0 }, Point2D{ 0, 4 });    // 正常三角形
		//Triangle tri2(Point2D{ 0, 0 }, Point2D{ 1, 1 }, Point2D{ 1, 3 });    // 非法三角形
		//Triangle tri3(Point2D{ 0, 0 }, Point2D{ 0, 0 }, Point2D{ 0, 5 });    // 零边长
		Triangle tri4(Point2D{ 0, 0 }, Point2D{ -2, 0 }, Point2D{ 0, 4 });   // 

		std::cout << "Triangle1 (3-4-5) 面积: " << tri1.getArea() << std::endl;
		//std::cout << "Triangle2 (1-1-3) 面积: " << tri2.getArea() << std::endl;
		//std::cout << "Triangle3 (0-4-5) 面积: " << tri3.getArea() << std::endl;
		std::cout << "Triangle4 (2-√20-4) 面积: " << tri4.getArea() << std::endl;
		// 测试 Cylinder 类
		std::cout << "\n=== Cylinder 测试 ===" << std::endl;
		Cylinder cylinder1;
		cylinder1.setRadius(5);
		cylinder1.setHeight(10);
		cylinder1.setCenter(Point2D{ 0, 0 });
		Cylinder cylinder2;
		cylinder2.setRadius(0);
		cylinder2.setHeight(10);
		Cylinder cylinder3;
		cylinder3.setRadius(-5);
		cylinder3.setHeight(10);
		std::cout << "Cylinder1 (半径5, 高10) 面积: " << cylinder1.getArea() << std::endl;
		std::cout << "Cylinder2 (半径0, 高10) 面积: " << cylinder2.getArea() << std::endl;
		std::cout << "Cylinder3 (半径-5, 高10) 面积: " << cylinder3.getArea() << std::endl;

		// 测试 Sphere 类
		std::cout << "\n=== Sphere 测试 ===" << std::endl;
		Sphere sphere1;
		sphere1.setRadius(5);
		sphere1.setCenter(Point2D{ 0, 0 });
		Sphere sphere2;
		sphere2.setRadius(0);
		Sphere sphere3;
		sphere3.setRadius(-5);
		std::cout << "Sphere1 (半径5) 面积: " << sphere1.getArea() << std::endl;
		std::cout << "Sphere2 (半径0) 面积: " << sphere2.getArea() << std::endl;
		std::cout << "Sphere3 (半径-5) 面积: " << sphere3.getArea() << std::endl;

		// 测试 Cube 类
		std::cout << "\n=== Cube 测试 ===" << std::endl;
		Cube cube1;
		cube1.setSide(5);
		cube1.setCenter(Point2D{ 0, 0 });
		Cube cube2;
		cube2.setSide(0);
		Cube cube3;
		cube3.setSide(-5);
		std::cout << "Cube1 (边长5) 面积: " << cube1.getArea() << std::endl;
		std::cout << "Cube2 (边长0) 面积: " << cube2.getArea() << std::endl;
		std::cout << "Cube3 (边长-5) 面积: " << cube3.getArea() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "捕获到异常: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "捕获到未知异常" << std::endl;
	}

	return 0;
}
