#ifndef POINT_H
#define POINT_H
struct Point {
    double x;
    double y;
    double z;

    // Constructor
    Point(double xVal = 0.0f, double yVal = 0.0f, double zVal = 0.0f)
        : x(xVal), y(yVal), z(zVal) {
    }
    // Constructor that takes integers
    Point(int xVal, int yVal, int zVal)
        : x(static_cast<double>(xVal)), y(static_cast<double>(yVal)), z(static_cast<double>(zVal)) {
    }

    // Overloaded assignment operator
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y, z + other.z);
    }

    // Overloaded subtraction operator
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y, z - other.z);
    }

    // Overloaded multiplication operator
    Point operator*(double scalar) const {
        return Point(x * scalar, y * scalar, z * scalar);
    }
    Point operator*(float scalar) const {
        double s = static_cast<double>(scalar);
        return Point(x * s, y * s, z * s);
    }
    Point operator/(float scalar) const {
        double s = static_cast<double>(scalar);
        return Point(x * s, y * s, z * s);
    }

};
#endif
