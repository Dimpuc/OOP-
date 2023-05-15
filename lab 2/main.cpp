#include <iostream>
#include <cmath>

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle() : side1(0), side2(0), side3(0) {}

    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    void setSides(double s1, double s2, double s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    double getSide1() const {
        return side1;
    }

    double getSide2() const {
        return side2;
    }

    double getSide3() const {
        return side3;
    }

    double getArea() const {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void print_sqr() const {
        std::cout << "Side 1: " << side1 << std::endl;
        std::cout << "Side 2: " << side2 << std::endl;
        std::cout << "Side 3: " << side3 << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }
};

Triangle frd(const Triangle& t1, const Triangle& t2) {
    double sumSide1 = t1.getSide1() + t2.getSide1();
    double sumSide2 = t1.getSide2() + t2.getSide2();
    double sumSide3 = t1.getSide3() + t2.getSide3();
    return Triangle(sumSide1, sumSide2, sumSide3);
}

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2;
    t2.setSides(6, 8, 10);

    t1.print_sqr();
    t2.print_sqr();

    Triangle t3 = frd(t1, t2);
    t3.print_sqr();

    return 0;
}