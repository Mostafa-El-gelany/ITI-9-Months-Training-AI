#include <iostream>

using namespace std;

class parent
{
    int x,y;
public:
    parent()
    {
        x=0;
        y=0;
    }
    parent(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    void set_x(int x)
    {
        this->x=x;
    }
    void set_y(int y)
    {
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
    int add()
    {
        return x+y;
    }
};

class child:public parent
{
    int z;
public:
    child():parent()
    {
        z=0;
    }
    child(int x,int y,int z):parent(x,y)
    {
        this->z=z;
    }
    void set_z(int z)
    {
        this->z=z;
    }
    int get_z()
    {
        return z;
    }
    int add()
    {
        return parent::add()+z;
    }
};

int main()
{
    parent p(2,9);
    cout<<p.add()<<"\n";
    child c(2,5,9);
    cout<<c.add();

    return 0;
}
