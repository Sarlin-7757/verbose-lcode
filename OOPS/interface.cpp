#include <iostream>
#include <cmath> // For M_PI
using namespace std;

// Rule 1: Use Abstract Classes
// Rule 2: Prefix Interface Names
class IShape {
public:
    // Rule 4: Public Access
    virtual void draw() const = 0; // Pure virtual method to draw the shape
    virtual double calculateArea() const = 0; // Pure virtual method to calculate area

    // Rule 3: No Member Data
    virtual ~IShape() = default; // Virtual destructor for proper cleanup
};

// Rule 6: Implement All Methods
class Circle : public IShape {
private:
    double radius;
public:
    explicit Circle(double r) : radius(r) {}

    // Rule 5: Explicit virtual and override
    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public IShape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a Rectangle with width " << width << " and height " << height << endl;
    }

    double calculateArea() const override {
        return width * height;
    }
};

// Rule 9: Interface Segregation and Rule 7: Keep It Focused
// IColoredShape demonstrates another interface
class IColoredShape {
public:
    virtual void setColor(const string& color) = 0;
    virtual string getColor() const = 0;
    virtual ~IColoredShape() = default;
};

class ColoredCircle : public Circle, public IColoredShape {
private:
    string color;
public:
    ColoredCircle(double r, const string& c) : Circle(r), color(c) {}

    void setColor(const string& c) override {
        color = c;
    }

    string getColor() const override {
        return color;
    }

    void draw() const override {
        Circle::draw();
        cout << "Color: " << color << endl;
    }
};

int main() {
    IShape* shape1 = new Circle(5.0);
    shape1->draw();
    cout << "Area: " << shape1->calculateArea() << endl;

    IShape* shape2 = new Rectangle(4.0, 6.0);
    shape2->draw();
    cout << "Area: " << shape2->calculateArea() << endl;

    ColoredCircle coloredCircle(7.0, "Red");
    coloredCircle.draw();
    cout << "Area: " << coloredCircle.calculateArea() << endl;

    delete shape1;
    delete shape2;

    return 0;
}

