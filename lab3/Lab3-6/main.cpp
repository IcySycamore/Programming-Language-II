#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

int main() {
	try {
		// ���� Circle ��
		std::cout << "=== Circle ���� ===" << std::endl;
		Circle circle1(Point2D{ 0, 0 }, 5.0);  // �����뾶
		Circle circle2(Point2D{ 0, 0 }, 0);   // �뾶Ϊ0
		Circle circle3(Point2D{ 0, 0 }, -1);  // ���뾶

		std::cout << "Circle1 (�뾶5) ���: " << circle1.area() << std::endl;
		std::cout << "Circle2 (�뾶0) ���: " << circle2.area() << std::endl;
		std::cout << "Circle3 (�뾶-1) ���: " << circle3.area() << std::endl;

		// ���� Rectangle ��
		std::cout << "\n=== Rectangle ���� ===" << std::endl;
		Rectangle rect1(Point2D{ 0, 0 }, Point2D{ 4, 6 });
		Rectangle rect2(Point2D{ 0, 0 }, Point2D{ 0, 5 });
		Rectangle rect3(Point2D{ 0, 0 }, Point2D{ -2, 3 });

		std::cout << "Rectangle1 (4x6) ���: " << rect1.area() << std::endl;
		std::cout << "Rectangle2 (0x5) ���: " << rect2.area() << std::endl;
		std::cout << "Rectangle3 (2x3) ���: " << rect3.area() << std::endl;

		// ���� Square ��
		std::cout << "\n=== Square ���� ===" << std::endl;
		Square square1(Point2D{ 0, 0 }, 5);
		Square square2(Point2D{ 0, 0 }, 0);
		Square square3(Point2D{ 0, 0 }, -3);

		std::cout << "Square1 (�߳�5) ���: " << square1.area() << std::endl;
		std::cout << "Square2 (�߳�0) ���: " << square2.area() << std::endl;
		std::cout << "Square3 (�߳�-3) ���: " << square3.area() << std::endl;

		// ���� Triangle ��
		std::cout << "\n=== Triangle ���� ===" << std::endl;
		Triangle tri1(Point2D{ 0, 0 }, Point2D{ 3, 0 }, Point2D{ 0, 4 });    // ����������
		//Triangle tri2(Point2D{ 0, 0 }, Point2D{ 1, 1 }, Point2D{ 1, 3 });    // �Ƿ�������
		//Triangle tri3(Point2D{ 0, 0 }, Point2D{ 0, 0 }, Point2D{ 0, 5 });    // ��߳�
		Triangle tri4(Point2D{ 0, 0 }, Point2D{ -2, 0 }, Point2D{ 0, 4 });   // 

		std::cout << "Triangle1 (3-4-5) ���: " << tri1.area() << std::endl;
		//std::cout << "Triangle2 (1-1-3) ���: " << tri2.area() << std::endl;
		//std::cout << "Triangle3 (0-4-5) ���: " << tri3.area() << std::endl;
		std::cout << "Triangle4 (2-��20-4) ���: " << tri4.area() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "�����쳣: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "����δ֪�쳣" << std::endl;
	}

	return 0;
}
