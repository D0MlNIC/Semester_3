#include <iostream>
#include <cmath>

using namespace std;

class Shape {
    protected:
        pair<float,float> position;
        string colors;
        double boarderThickness;
    public:
        Shape(string c, double bT ,pair<float,float> p) 
        : position(p), colors(c), boarderThickness(bT) {};

        virtual void draw() const = 0;
        virtual double calculateArea() const = 0;
        virtual double calculatePerimeter() const = 0;

        virtual ~Shape() {};
};

class Circle : public Shape {
    private: 
        float radius;
    public:
        Circle( string c, double bT, pair<float,float> p, float r) 
        : Shape(c, bT, p), radius(r) {};

        void draw() const override {
            cout << "Drawing a circle at position (" << position.first << ", " << position.second << ") with radius " << radius << endl; 
        }

        double calculateArea() const override {
            return M_PI * pow(radius, 2);
        }

        double calculatePerimeter() const override {
            return 2 * M_PI * radius;
        }
};

class Rectangle : public Shape {
    private:
        float width,height;
    public:
        Rectangle (string c, double bT, pair<float,float> p, float w, float h)
        : Shape(c, bT, p), width(w), height(h) {};

        void draw() const override {
            cout << "Drawing a rectangle at position (" << position.first << ", " << position.second << ") with width " << width << " and height " << height << endl;
        }

        double calculateArea() const override {
            return width * height;
        }

        double calculatePerimeter() const override {
            return 2 * (width + height);
        }
};

class Triangle : public Shape {
    private:
        float base,height;
    public:
        Triangle(string c, double bT, pair<float,float> p, float b, float h ) 
        : Shape(c, bT, p), base(b), height(h) {};

        void draw() const override {
            cout << "Drawing a triangle at position (" << position.first << ", " << position.second << ") with base " << base << " and height " << height << endl;
        }
        double calculateArea() const override {
            return 0.5 * base * height;
        }

        double calculatePerimeter() const override {
            double s = (base + height + sqrt(pow(base, 2) + pow(height, 2)));
            return s;
        }
};


class Polygon : public Shape {
    private:
        double perimeter, area;
        int vetices;

    public:
        Polygon(string c, double bT, pair<float,float> p, int v ,double pa, double a) 
        : Shape(c, bT, p), vetices(v), perimeter(pa), area(a) {};

        void draw() const override {
            cout << "Drawing a polygon at position (" << position.first << ", " << position.second << ") with total vertives" << vetices << endl;
        }

        double calculateArea() const override {
            return area;
        }

        double calculatePerimeter() const override {
            return perimeter;
        }
    };
    

    int main() {
        Circle c("Red", 2.0, {10, 10}, 5.0);
        Rectangle r("Blue", 1.5, {0, 0}, 4.0, 6.0);
        Triangle t("Green", 1.0, {5, 5}, 3.0, 4.0);
        Polygon p("Yellow", 1.2, {2, 2}, 5, 20.0, 30.0);
    
        c.draw();
        cout << "Circle Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << endl;
        
        r.draw();
        cout << "Rectangle Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << endl;
        
        t.draw();
        cout << "Triangle Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << endl;
        
        p.draw();
        cout << "Polygon Area: " << p.calculateArea() << ", Perimeter: " << p.calculatePerimeter() << endl;
        
        return 0;
    }
    