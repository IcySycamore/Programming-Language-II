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
		// ���� Circle ��
		std::cout << "=== Circle ���� ===" << std::endl;
		Circle circle1(Point2D{ 0, 0 }, 5.0);  // �����뾶
		Circle circle2(Point2D{ 0, 0 }, 0);   // �뾶Ϊ0
		Circle circle3(Point2D{ 0, 0 }, -1);  // ���뾶

		std::cout << "Circle1 (�뾶5) ���: " << circle1.getArea() << std::endl;
		std::cout << "Circle2 (�뾶0) ���: " << circle2.getArea() << std::endl;
		std::cout << "Circle3 (�뾶-1) ���: " << circle3.getArea() << std::endl;

		// ���� Rectangle ��
		std::cout << "\n=== Rectangle ���� ===" << std::endl;
		Rectangle rect1(Point2D{ 0, 0 }, Point2D{ 4, 6 });
		Rectangle rect2(Point2D{ 0, 0 }, Point2D{ 0, 5 });
		Rectangle rect3(Point2D{ 0, 0 }, Point2D{ -2, 3 });

		std::cout << "Rectangle1 (4x6) ���: " << rect1.getArea() << std::endl;
		std::cout << "Rectangle2 (0x5) ���: " << rect2.getArea() << std::endl;
		std::cout << "Rectangle3 (2x3) ���: " << rect3.getArea() << std::endl;

		// ���� Square ��
		std::cout << "\n=== Square ���� ===" << std::endl;
		Square square1(Point2D{ 0, 0 }, 5);
		Square square2(Point2D{ 0, 0 }, 0);
		Square square3(Point2D{ 0, 0 }, -3);

		std::cout << "Square1 (�߳�5) ���: " << square1.getArea() << std::endl;
		std::cout << "Square2 (�߳�0) ���: " << square2.getArea() << std::endl;
		std::cout << "Square3 (�߳�-3) ���: " << square3.getArea() << std::endl;

		// ���� Triangle ��
		std::cout << "\n=== Triangle ���� ===" << std::endl;
		Triangle tri1(Point2D{ 0, 0 }, Point2D{ 3, 0 }, Point2D{ 0, 4 });    // ����������
		//Triangle tri2(Point2D{ 0, 0 }, Point2D{ 1, 1 }, Point2D{ 1, 3 });    // �Ƿ�������
		//Triangle tri3(Point2D{ 0, 0 }, Point2D{ 0, 0 }, Point2D{ 0, 5 });    // ��߳�
		Triangle tri4(Point2D{ 0, 0 }, Point2D{ -2, 0 }, Point2D{ 0, 4 });   // 

		std::cout << "Triangle1 (3-4-5) ���: " << tri1.getArea() << std::endl;
		//std::cout << "Triangle2 (1-1-3) ���: " << tri2.getArea() << std::endl;
		//std::cout << "Triangle3 (0-4-5) ���: " << tri3.getArea() << std::endl;
		std::cout << "Triangle4 (2-��20-4) ���: " << tri4.getArea() << std::endl;
		// ���� Cylinder ��
		std::cout << "\n=== Cylinder ���� ===" << std::endl;
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
		std::cout << "Cylinder1 (�뾶5, ��10) ���: " << cylinder1.getArea() << std::endl;
		std::cout << "Cylinder2 (�뾶0, ��10) ���: " << cylinder2.getArea() << std::endl;
		std::cout << "Cylinder3 (�뾶-5, ��10) ���: " << cylinder3.getArea() << std::endl;

		// ���� Sphere ��
		std::cout << "\n=== Sphere ���� ===" << std::endl;
		Sphere sphere1;
		sphere1.setRadius(5);
		sphere1.setCenter(Point2D{ 0, 0 });
		Sphere sphere2;
		sphere2.setRadius(0);
		Sphere sphere3;
		sphere3.setRadius(-5);
		std::cout << "Sphere1 (�뾶5) ���: " << sphere1.getArea() << std::endl;
		std::cout << "Sphere2 (�뾶0) ���: " << sphere2.getArea() << std::endl;
		std::cout << "Sphere3 (�뾶-5) ���: " << sphere3.getArea() << std::endl;

		// ���� Cube ��
		std::cout << "\n=== Cube ���� ===" << std::endl;
		Cube cube1;
		cube1.setSide(5);
		cube1.setCenter(Point2D{ 0, 0 });
		Cube cube2;
		cube2.setSide(0);
		Cube cube3;
		cube3.setSide(-5);
		std::cout << "Cube1 (�߳�5) ���: " << cube1.getArea() << std::endl;
		std::cout << "Cube2 (�߳�0) ���: " << cube2.getArea() << std::endl;
		std::cout << "Cube3 (�߳�-5) ���: " << cube3.getArea() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "�����쳣: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "����δ֪�쳣" << std::endl;
	}

	return 0;
}
