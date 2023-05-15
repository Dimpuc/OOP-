#include <iostream>
#include <cmath>

class Triangle {
private:
    double a;
    double b;
    double c;

public:
    Triangle() : a(0), b(0), c(0) {}

    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double getSideA() const {
        return a;
    }

    double getSideB() const {
        return b;
    }

    double getSideC() const {
        return c;
    }

    void setSides(double sideA, double sideB, double sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    double getArea() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    Triangle operator+(const Triangle& other) const {
        double sumA = a + other.a;
        double sumB = b + other.b;
        double sumC = c + other.c;
        return Triangle(sumA, sumB, sumC);
    }

    Triangle& operator++() {
        ++a;
        ++b;
        ++c;
        return *this;
    }

    Triangle operator++(int) {
        Triangle temp = *this;
        ++(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
        os << "Side A: " << triangle.a << ", Side B: " << triangle.b << ", Side C: " << triangle.c
           << ", Area: " << triangle.getArea();
        return os;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2(2, 3, 4);

    std::cout << "Triangle 1: " << t1 << std::endl;
    std::cout << "Triangle 2: " << t2 << std::endl;

    Triangle t3 = t1 + t2;
    std::cout << "Triangle 3 (Sum of Triangle 1 and Triangle 2): " << t3 << std::endl;

    ++t3;
    std::cout << "Triangle 3 after increment: " << t3 << std::endl;

    Triangle t4 = t3++;
    std::cout << "Triangle 3 (post-increment): " << t3 << std::endl;
    std::cout << "Triangle 4 (copy of Triangle 3 before increment): " << t4 << std::endl;

    return 0;
}