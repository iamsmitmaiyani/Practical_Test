#include <iostream>
#include <cmath> // For M_PI constant

// Abstract class
class Shape {
public:
    // Pure virtual functions
    virtual double calculateArea() const = 0;
    virtual void draw() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Concrete class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implement calculateArea for Circle
    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    // Implement draw for Circle
    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }
};

// Concrete class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implement calculateArea for Rectangle
    double calculateArea() const override {
        return width * height;
    }

    // Implement draw for Rectangle
    void draw() const override {
        std::cout << "Drawing a Rectangle with width " << width << " and height " << height << std::endl;
    }
};

int main() {
    // Create an array of Shape pointers
    const int shapeCount = 2;
    Shape* shapes[shapeCount];

    // Instantiate Circle and Rectangle objects
    Circle circle(5.0); // Radius = 5.0
    Rectangle rectangle(4.0, 6.0); // Width = 4.0, Height = 6.0

    // Assign objects to Shape pointers
    shapes[0] = &circle;
    shapes[1] = &rectangle;

    // Demonstrate polymorphism
    for (int i = 0; i < shapeCount; ++i) {
        std::cout << "Area: " << shapes[i]->calculateArea() << std::endl;
        shapes[i]->draw();
        std::cout << std::endl;
    }

    return 0;
}
