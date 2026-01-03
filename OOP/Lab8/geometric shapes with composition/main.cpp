#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
class point{
    int x,y;
public:
    point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
        textattr(5);
        cout<<"point created successfully\n";
        textattr(7);
    }
    ~point()
    {
        textattr(5);
        cout<<"point destroyed successfully\n";
        textattr(7);
    }
    void set_point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    void print()
    {
        cout<<"x ->"<<x<<" y ->"<<y<<"\n";
    }
};

class triangle
{
    point p1,p2,p3;
public:
    triangle(int x1,int y1,int x2,int y2,int x3,int y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {
        textattr(2);
        cout<<"triangle created successfully\n";
        textattr(7);
    }
    ~triangle()
    {
        textattr(2);
        cout<<"triangle destroyed successfully\n";
        textattr(7);
    }
    void set_triangle(int x1,int y1,int x2,int y2,int x3,int y3)
    {
        p1.set_point(x1,y1);
        p2.set_point(x2,y2);
        p3.set_point(x3,y3);
    }
    void set_p1(int x1,int y1)
    {
        p1.set_point(x1,y1);
    }
    void set_p2(int x2,int y2)
    {
        p2.set_point(x2,y2);
    }
    void set_p3(int x3,int y3)
    {
        p3.set_point(x3,y3);
    }
    point get_p1()
    {
        return p1;
    }
    point get_p2()
    {
        return p2;
    }
    point get_p3()
    {
        return p3;
    }
    void print()
    {
        p1.print();
        p2.print();
        p3.print();
    }
};

class rectangle
{
    point ul,lr;
public:
    rectangle(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        textattr(3);
        cout<<"rectangle created successfully\n";
        textattr(7);

    }
    ~rectangle()
    {
        textattr(3);
        cout<<"rectangle destroyed successfully\n";
        textattr(7);
    }
    void set_rectangle(int x1,int y1,int x2,int y2)
    {
        ul.set_point(x1,y1);
        lr.set_point(x2,y2);
    }
    void set_ul(int x1,int y1)
    {
        ul.set_point(x1,y1);
    }
    void set_lr(int x2,int y2)
    {
        lr.set_point(x2,y2);
    }
    point get_ul()
    {
        return ul;
    }
    point get_lr()
    {
        return lr;
    }

    void print()
    {
        ul.print();
        lr.print();
    }
};

class circle
{
    point center;
    int r;
public:

    circle(int x,int y,int r):center(x,y)
    {
        this->r=r;
        textattr(4);
        cout<<"circle created successfully\n";
        textattr(7);
    }
    ~circle()
    {
        textattr(4);
        cout<<"circle destroyed successfully\n";
        textattr(7);
    }
    void set_circle(int x,int y,int r)
    {
        this->r=r;
        center.set_point(x,y);
    }
    point get_center()
    {
        return center;
    }
    int get_r()
    {
        return r;
    }
    void print()
    {
        center.print();
        cout<<"raduis is "<<r<<"\n";
    }
};

int main()
{
    triangle t(5,3,6,7,9,1);
    textattr(2);
    t.print();
    textattr(7);
    rectangle r(1,3,5,2);
    textattr(3);
    r.print();
    textattr(7);
    circle c(0,0,6);
    textattr(4);
    c.print();
    textattr(7);
    return 0;
}
