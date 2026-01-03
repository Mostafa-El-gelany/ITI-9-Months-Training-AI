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
    point *p1,*p2,*p3;
public:
    triangle()
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
    void set_triangle(point *p1,point *p2,point *p3)
    {
        this->p1=p1;
        this->p2=p2;
        this->p3=p3;
    }
    void set_p1(point *p)
    {
        p1=p;
    }
    void set_p2(point *p)
    {
        p2=p;
    }
    void set_p3(point *p)
    {
        p3=p;
    }
    point get_p1()
    {
        return *p1;
    }
    point get_p2()
    {
        return *p2;
    }
    point get_p3()
    {
        return *p3;
    }
    void print()
    {
        p1->print();
        p2->print();
        p3->print();
    }
};

class rectangle
{
    point *ul,*lr;
public:
    rectangle()
    {
        textattr(3);
        cout<<"rectangle created successfully\n";
        textattr(7);
    }
    ~rectangle()
    {
        textattr(3);
        cout<<"rectangle destroyed successfully\n";
        textattr(3);
    }
    void set_rectangle(point *ul,point *lr)
    {
        this->ul=ul;
        this->lr=lr;
    }
    void set_ul(point *ul)
    {
        this->ul=ul;
    }
    void set_lr(point *lr)
    {
        this->lr=lr;
    }
    point get_ul()
    {
        return *ul;
    }
    point get_lr()
    {
        return *lr;
    }
    void print()
    {
        ul->print();
        lr->print();
    }

};

class circle
{
    point *center;
    int r;
public:

    circle()
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
    void set_circle(point *p,int r)
    {
        this->r=r;
        center=p;
    }
    point get_center()
    {
        return *center;
    }
    int get_r()
    {
        return r;
    }
    void print()
    {
        center->print();
        cout<<"raduis is "<<r<<"\n";
    }
};

int main()
{
    point p1(1,2),p2(2,3),p3(3,4),p4(4,5),p5(5,6),p6(6,7);
    triangle t;
    t.set_triangle(&p1,&p2,&p3);
    textattr(2);
    t.print();
    textattr(7);
    rectangle r;
    r.set_rectangle(&p4,&p5);
    textattr(3);
    r.print();
    textattr(7);
    circle c;
    c.set_circle(&p6,10);
    textattr(4);
    c.print();
    textattr(7);
    return 0;
}
