#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(int x, int y) :x(x), y(y){}
    int x, y;
    virtual void print(void) {
        cout << "shape:" << x << "," << y;
    }
    virtual double area() = 0;
};

class Rect :public Shape {
public:
    Rect(int x,int y, int a,int b) : Shape(x,y),a(a),b(b){}
    void print(void) {
        Shape::print();
        cout << ", " << a << ", " <<b << endl;
        }
    double area(void) {
        return a * b;

    }
private :
    int a, b;
};

class Circle : public Shape {
public:
    Circle(int x, int y, int r) : Shape(x, y), r(r) {}
    
        void print(void){
            Shape::print();
            cout << ", " << r << endl;
        }
        double area(void) {
            return 3.14 * r * r;

        }
    
private:
    int r;
};
int main(int argc, char** argv)
{
    Rect r1(1, -2, 2, 3);
        //r1.print();//Shape::print();
        Circle c1(-1, -4, 10);
    //c1.print();
    Shape* m[] = { &r1, &c1 };
    m[0]->print();
    m[1]->print();
   cout << "rect:"<< m[0]->area()<<endl;
   cout << "circle:" << m[1]->area()<<endl;
    return 0;

}

