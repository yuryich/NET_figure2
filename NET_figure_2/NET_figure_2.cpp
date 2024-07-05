#include <iostream>
#include <string>
using namespace std;

class Figure {
public:
	Figure(int sides_count, const string& name)
		: sides_count(sides_count), name(name), print_func(nullptr) {}

	int get_sides_count() const {
		return sides_count;
	}

	string get_name() const {
		return name;
	}

	void print_info() const {
		if (print_func) {
			print_func(this);
		}
	}

protected:
	int sides_count;
	string name;
	void(*print_func)(const Figure*);

	void set_print_func(void(*func)(const Figure*)) {
		print_func = func;
	}
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Figure(3, "Треугольник"), side_a(a), side_b(b), side_c(c), degree_A(A), degree_B(B), degree_C(C) {
		set_print_func(print_triangle_info);
	}

	static void print_triangle_info(const Figure* fig) {
		const Triangle* tri = static_cast<const Triangle*>(fig);
		cout << tri->name << ":" << endl;
		cout << "Стороны: a=" << tri->side_a << " b=" << tri->side_b << " c=" << tri->side_c << endl;
		cout << "Углы: A=" << tri->degree_A << " B=" << tri->degree_B << " C=" << tri->degree_C << endl;
		cout << endl;
	}

protected:
	int side_a, side_b, side_c;
	int degree_A, degree_B, degree_C;
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Figure(4, "Четырёхугольник"), side_a(a), side_b(b), side_c(c), side_d(d), degree_A(A), degree_B(B), degree_C(C), degree_D(D) {
		set_print_func(print_quadrangle_info);
	}

	static void print_quadrangle_info(const Figure* fig) {
		const Quadrangle* quad = static_cast<const Quadrangle*>(fig);
		cout << quad->name << ":" << endl;
		cout << "Стороны: a=" << quad->side_a << " b=" << quad->side_b << " c=" << quad->side_c << " d=" << quad->side_d << endl;
		cout << "Углы: A=" << quad->degree_A << " B=" << quad->degree_B << " C=" << quad->degree_C << " D=" << quad->degree_D << endl;
		cout << endl;
	}

protected:
	int side_a, side_b, side_c, side_d;
	int degree_A, degree_B, degree_C, degree_D;
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadrangle(a, b, a, b, A, B, A, B) {
		name = "Параллелограмм";
	}
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b)
		: Parallelogram(a, b, 90, 90) {
		name = "Прямоугольник";
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B)
		: Parallelogram(a, a, A, B) {
		name = "Ромб";
	}
};

class Square : public Rhombus {
public:
	Square(int a)
		: Rhombus(a, 90, 90) {
		name = "Квадрат";
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	RightTriangle right_triangle(10, 20, 30, 50, 60);
	IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
	EquilateralTriangle equilateral_triangle(30);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhombus rhombus(30, 30, 40);

	triangle.print_info();
	right_triangle.print_info();
	isosceles_triangle.print_info();
	equilateral_triangle.print_info();
	quadrangle.print_info();
	rectangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhombus.print_info();

}