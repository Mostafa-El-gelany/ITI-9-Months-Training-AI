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

    virtual double calc_area()=0;

};
class rectangle:public shape
{

public:
    rectangle():shape()
    {

    }
    rectangle(int dim1,int dim2):shape(dim1,dim2)
    {

    }
    double calc_area()
    {
        return get_dim1()*get_dim2();
    }
};

class circle:public shape
{

public:
    circle():shape()
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
    triangle():shape()
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

class square:public rectangle
{

public:
    square():rectangle()
    {

    }
    square(int dim1):rectangle(dim1,dim1)
    {

    }
    double calc_area()
    {
        return get_dim1()*get_dim1();
    }
    void print()
    {
        cout<<"Dimension of square = "<<get_dim1()<<"\n";
    }
};

double myfun(shape &var)
{
    cout<<"area of shape = "<<var.calc_area()<<"\n";
}
double myfun(shape *var)
{
    cout<<"area of shape = "<<var->calc_area()<<"\n";
}

void get_sum(shape **arr,int len)
{
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum+=arr[i]->calc_area();
    }
    cout<<"total area = "<<sum<<"\n";
}
int main()
{
    int sum=0;
    shape *arr[4];
    arr[0]=new circle(3);
    arr[1]=new square(5);
    arr[2]=new rectangle(9,6);
    arr[3]=new triangle(7,4);
    get_sum(arr,4);


    triangle s(5,3);
    myfun(s);
    myfun(&s);
    return 0;
}
