#include <iostream>

using namespace std;
class shape
{
    int dim1,dim2;
public:
    shape()
    {
        dim1=0,dim2=0;
    }
    shape(int dim1,int dim2)
    {
        if(dim1<0||dim2<0)
        {
            cout<<"dimension can't be negative\n";
            this->dim1=0;
            this->dim2=0;
        }
        this->dim1=dim1;
        this->dim2=dim2;
    }
    void set_shape()
    {
        if(dim1<0||dim2<0)
        {
            cout<<"dimension can't be negative\n";
        }
        this->dim1=dim1;
        this->dim2=dim2;
    }
    void set_dim1(int dim)
    {
        if(dim<0)cout<<"dimension can't be negative\n";
        else
        {
            dim1=dim;
        }
    }

    void set_dim2(int dim)
    {
        if(dim<0)cout<<"dimension can't be negative\n";
        dim2=dim;
    }
    int get_dim1()
    {
        return dim1;
    }
    int get_dim2()
    {
        return dim2;
    }
    void print()
    {
        cout<<"dimension 1 = "<<dim1<<'\n';
        cout<<"dimension 2 = "<<dim2<<'\n';
    }
};
class rectangle:public shape
{

public:
    rectangle()
    {

    }
    rectangle(int dim1,int dim2):shape(dim1,dim2)
    {

    }
    int calc_area()
    {
        return get_dim1()*get_dim2();
    }
};

class circle:public shape
{

public:
    circle()
    {

    }
    circle(int r)
    {
        set_dim1(r);
    }
    void set_dim2(int r)
    {
        shape::set_dim1(r);
    }
    int get_dim2()
    {
        return shape::get_dim1();
    }
    double calc_area()
    {
        return get_dim1()*get_dim1()*3.14;
    }
    void print()
    {
        cout<<"raduis of circle = "<<get_dim1()<<'\n';
    }
};
class triangle:public shape
{

public:
    triangle()
    {

    }
    triangle(int dim1,int dim2):shape(dim1,dim2)
    {

    }
    double calc_area()
    {
        return get_dim1()*get_dim2()/2.0;
    }
};
int main()
{
    rectangle r(3,5);
    cout<<r.calc_area()<<endl;

    triangle t(9,7);
    cout<<t.calc_area()<<endl;

    circle c(10);
    cout<<c.calc_area();
    return 0;
}
