#include <iostream>
#include <string>

class Figure {
public:
	Figure(int a) :Figure("Figure", a){
	}
	virtual void print_info() {
		std::cout << name << ":" << std::endl;
		if (check())
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;
		std::cout << "The amount of edges:" << amount_of_edges << std::endl;
	}
	  virtual bool check(){
		if (amount_of_edges == 0)
			return true;
		else
			return false;
	}
protected:
	Figure(std::string name, int amount_of_edges) {
		this->name = name;
		this->amount_of_edges = amount_of_edges;
	}
	int amount_of_edges;
	std::string name;
};

class Triangle:public Figure {
public:
	Triangle(int amount):Triangle(10,10,20,60,40,70,amount,"Triangle") {}
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
		std::cout << "Angles: " << "A = " << get_A() << " B = " << get_B() << " C = " << get_C() <<  std::endl;
	}

	  bool check() override{
		if ((amount_of_edges == 3 )&&( A + B + C == 180))
			return true;
		else
			return false;
	}
protected:
	Triangle(double a, double b, double c, double A, double B, double C, int amount,std::string name):Figure(name,amount) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	double a, b, c;
	double A, B, C;
};

class isosceles_triangle : public Triangle {
protected:
	isosceles_triangle(double a, double b, double A, double B,std::string name,int amount) :Triangle(a, b, a, A, B, A,amount,name) {
	}
public:
	isosceles_triangle(int amount) :isosceles_triangle(20, 10, 50, 80,"isosceles_triangle",amount) {
	}
	bool check() override {
		if (Triangle::check() && A == C && a == c)
			return true;
		else
			return false;
	}
};

class equilateral_triangle : public Triangle {
protected:
	equilateral_triangle(double a, double A,int amount,std::string name) :Triangle(a, a, a, A, A, A,amount,name) {
	}
public:
	equilateral_triangle(int amount) :equilateral_triangle(25, 50,amount, "equilateral_triangle") {
	}
	bool check() override {
		if (Triangle::check() && A == 60 && B == A && C == A && a == b && b == c)
			return true;
		else
			return false;
	}
};

class right_triangle :public Triangle {
protected:
	right_triangle(double a,double b,double c, double A,double B, int amount, std::string name) :Triangle(a, b, c, A, B, 90, amount, name) {
	}
public:
	right_triangle(int amount) :right_triangle(10,20,30,45,45, amount, "right_triangle") {
	}
	bool check() override {
		if (Triangle::check() && C== 90)
			return true;
		else
			return false;
	}
};


class Quadrilateral :public Figure {
public:
	Quadrilateral(int amount) : Quadrilateral(10, 10, 20,30, 90, 90, 90,90, amount, "Quadrilateral") {}
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
		std::cout << "Edges: " << "a = " << get_a() << " b = " << get_b() << " c = " << get_c()<<" d = " << get_d() << std::endl;
		std::cout << "Angles: " << "A = " << get_A() << " B = " << get_B() << " C = " << get_C()<<" D = " << get_D() << std::endl;
	}

	bool check() override {
		if ((amount_of_edges == 4) && (A + B + C + D== 360))
			return true;
		else
			return false;
	}
protected:
	Quadrilateral(double a, double b, double c,double d, double A, double B, double C,double D, int amount, std::string name) :Figure(name, amount) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	double a, b, c, d;
	double A, B, C, D;
};

class parallelogram :public Quadrilateral {
protected:
	parallelogram(double a, double b, double A, double B,int amount, std::string name) :Quadrilateral(a, b, a, b, A, B, A, B, amount, name) {
	}
	
public:
	parallelogram(int amount) :parallelogram(10, 20, 150, 30,amount,"parallelogram") {
	}
	bool check() override {
		if (Quadrilateral::check() && a == c && b == d && A == C && B == D)
			return true;
		else
			return false;
	}
};


class rhombus :public parallelogram {
protected:
	rhombus(double a, double A, double B, int amount, std::string name) :parallelogram(a,a, A, B, amount, name){
	}
public:
	rhombus(int amount) :rhombus(10, 150, 30, amount, "rhombus") {
	}
	bool check() override {
		if (parallelogram::check() && a == b)
			return true;
		else
			return false;
	}
};

class square :public rhombus {
protected:
	square(double a, int amount, std::string name) :rhombus(a,90,90, amount, name) {}
public:
	square(int amount) :square(10, amount, "square") {
	}
	bool check() override{
		if (rhombus::check() && A == B && A == 90)
			return true;
		else
			return false;
	}
};

class rectangle : public parallelogram {
protected:
	rectangle(double a, double b, int amount, std::string name) :parallelogram(a, b, 90, 90, amount, name) {
	}
public:
	rectangle(int amount) :rectangle(10, 20, amount, "rectangle") {
	}
	bool check() override {
		if (parallelogram::check() && A == B && A == 90)
			return true;
		else
			return false;
	}
};

int main() {
	Figure a(0);
	a.print_info();
	std::cout << std::endl;

	Triangle t(3);
	t.print_info();
	std::cout << std::endl;

	isosceles_triangle b(3);
	b.print_info();
	std::cout << std::endl;

	equilateral_triangle e(3);
	e.print_info();
	std::cout << std::endl;

	right_triangle f(3);
	f.print_info();
	std::cout << std::endl;

	Quadrilateral r(4);
	r.print_info();
	std::cout << std::endl;

	parallelogram p(5);
	p.print_info();
	std::cout << std::endl;

	rhombus u(4);
	u.print_info();
	std::cout << std::endl;

	square x(4);
	x.print_info();
	std::cout << std::endl;

	rectangle y(4);
	y.print_info();
	std::cout << std::endl;

	
	return 0;
}