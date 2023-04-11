#include <iostream>
#include <cmath>

class Vector {
public:
    Vector() : x(0.0), y(0.0), z(0.0) {}
    Vector(float x, float y, float z) : x(x), y(y), z(z) {
        if (z < 0) {
            this->x = -this->x;
            this->y = -this->y;
            this->z = -this->z;
        }
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getZ() const {
        return z;
    }

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    void setZ(float z) {
        this->z = z;
    }

    void print() const {
        std::cout << "<" << x << " " << y << " " << z << ">\n";
    }

private:
    float x, y, z;
};

int main() {
    Vector v1;
    v1.print();

    Vector v2(1.0, 2.0, -3.0);
    v2.print();

    v2.setX(4.0);
    v2.setY(-5.0);
    v2.setZ(6.0);
    v2.print();

    return 0;
}