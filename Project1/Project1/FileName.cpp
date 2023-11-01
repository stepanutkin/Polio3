#include <iostream>
#include <string>

class Figure {
public:
	Figure(){
		amount_of_edges = 0;
		name = "Figure";
	}
	virtual void print_info() {
		std::cout << name << ":" << std::endl;
		if (check())
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;
		std::cout << "The amount of edges:" << amount_of_edges << std::endl;
	}
	virtual bool check() {
		if (amount_of_edges == 0)
			return true;
		else
			return false;
	}
protected:
	int amount_of_edges;
	std::string name;
};

class Triangle :public Figure {
public:
	Triangle(double a, double b, double c, double A, double B, double C){
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->name = "Triangle";
		this->amount_of_edges = 3;
	}
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	double get_c() {
		return c;
	}
	double get_A() {
		return A;
	}
	double get_B() {
		return B;
	}
	double get_C() {
		return C;
	}

	void print_info() override {
		Figure::print_info();
		std::cout << "Edges: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << std::endl;
		std::cout << "Angles: " << "A = " << get_A() << " B = " << get_B() << " C = " << get_C() << std::endl;
	}

	bool check() override {
		if ((amount_of_edges == 3) && (A + B + C == 180))
			return true;
		else
			return false;
	}
protected:
	double a, b, c;
	double A, B, C;
};

class isosceles_triangle : public Triangle {
public:
	isosceles_triangle(double a, double b, double A, double B) :Triangle(a, b, a, A, B, A) {
		this->name = "isosceles_triangle";
	}
	bool check() override {
		if (Triangle::check() && A == C && a == c)
			return true;
		else
			return false;
	}
};

class equilateral_triangle : public Triangle {
public:
	equilateral_triangle(double a) :Triangle(a, a, a, 60, 60, 60) {
		this->name = "equilateral_triangle";
	}

	bool check() override {
		if (Triangle::check() && A == 60 && B == A && C == A && a == b && b == c)
			return true;
		else
			return false;
	}
};

class right_triangle :public Triangle {
public:
	right_triangle(double a, double b, double c, double A, double B) :Triangle(a, b, c, A, B, 90) {
	}
	bool check() override {
		if (Triangle::check() && C == 90)
			return true;
		else
			return false;
	}
};


class Quadrilateral :public Figure {
public:
Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D){
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->name = "Quadrilateral";
		this->amount_of_edges = 4;
	}
	
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	double get_c() {
		return c;
	}
	double get_d() {
		return d;
	}
	double get_A() {
		return A;
	}
	double get_B() {
		return B;
	}
	double get_C() {
		return C;
	}
	double get_D() {
		return D;
	}

	void print_info() override {
		Figure::print_info();
		std::cout << "Edges: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c() << " d = " << get_d() << std::endl;
		std::cout << "Angles: " << "A = " << get_A() << " B = " << get_B() << " C = " << get_C() << " D = " << get_D() << std::endl;
	}

	bool check() override {
		if ((amount_of_edges == 4) && (A + B + C + D == 360))
			return true;
		else
			return false;
	}
protected:
	double a, b, c, d;
	double A, B, C, D;
};


class parallelogram :public Quadrilateral {
public:
	parallelogram(double a, double b, double A, double B) :Quadrilateral(a, b, a, b, A, B, A, B) {
		this->name = "parallelogram ";
	}
	bool check() override {
		if (Quadrilateral::check() && a == c && b == d && A == C && B == D)
			return true;
		else
			return false;
	}
};


class rhombus :public parallelogram {
public:
	rhombus(double a, double A, double B) :parallelogram(a, a, A, B) {
		this->name = "rhombus";
	}
	bool check() override {
		if (parallelogram::check() && a == b)
			return true;
		else
			return false;
	}
};

class square :public rhombus {
public:
	square(double a) :rhombus(a, 90, 90) {
		this->name = "square";
	}
	bool check() override {
		if (rhombus::check() && A == B && A == 90)
			return true;
		else
			return false;
	}
};

class rectangle : public parallelogram {
public:
	rectangle(double a, double b) :parallelogram(a, b, 90, 90) {
		this->name = "rectangle";
	}
	bool check() override {
		if (parallelogram::check() && A == B && A == 90)
			return true;
		else
			return false;
	}
};

int main() {
	Figure a;
	a.print_info();
	std::cout << std::endl;

	Triangle t(10, 20, 30, 40, 50, 60);
	t.print_info();
	std::cout << std::endl;

	isosceles_triangle b(20, 60, 70, 30);
	b.print_info();
	std::cout << std::endl;

	equilateral_triangle e(30);
	e.print_info();
	std::cout << std::endl;

	right_triangle f(30, 40, 50, 50, 60);
	f.print_info();
	std::cout << std::endl;

	Quadrilateral r(30, 40, 50, 60, 70, 80, 90, 100);
	r.print_info();
	std::cout << std::endl;

	parallelogram p(30, 40, 120, 60);
	p.print_info();
	std::cout << std::endl;

	rhombus u(10, 20, 30);
	u.print_info();
	std::cout << std::endl;

	square x(30);
	x.print_info();
	std::cout << std::endl;

	rectangle y(40, 50);
	y.print_info();
	std::cout << std::endl;
	return 0;
}