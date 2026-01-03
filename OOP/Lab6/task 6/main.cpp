#include <iostream>
#include <string.h>
using namespace std;

class emp{
    int id=0,age=0,salary=0;
    char name[20]="";

public:
    void set_id(int _id)
    {
        id=_id;
    }
    void set_age(int _age)
    {
        age=_age;
    }
    void set_salary(int _salary)
    {
        salary=_salary;
    }
    void set_name(char _name[])
    {
        strcpy(name,_name);
    }

    int get_id()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    int get_salary()
    {
        return salary;
    }
    char* get_name()
    {
        return name;
    }
    void print()
    {
        cout<<"employee's id is "<<id<<"\n";
        cout<<"employee's name is "<<name<<"\n";
        cout<<"employee's age is "<<age<<"\n";
        cout<<"employee's salary is "<<salary<<"\n";

    }
};

class ba{
    int id=0,balance=0;
    char name[20]="";

public:
    void set_id(int _id)
    {
        id=_id;
    }
    void set_balance(int _balance)
    {
        balance=_balance;
    }
    void set_name(char _name[])
    {
        strcpy(name,_name);
    }

    int get_id()
    {
        return id;
    }

    int get_balance()
    {
        return balance;
    }
    char* get_name()
    {
        return name;
    }

};

class cmplx{
    int real=0,image=0;
public:

    void set_real(int _real)
    {
        real=_real;
    }
    void set_image(int _image)
    {
        image=_image;
    }

    int get_real()
    {
        return real;
    }
    int get_image()
    {
        return image;
    }
    void print()
    {
        cout<<real<<'+'<<image<<'j';
    }
    void add(cmplx c)
    {
        real+=c.real;
        image+=c.image;
    }
};

cmplx subtract(cmplx a,cmplx b){
    cmplx ret;
    ret.set_image(a.get_image()-b.get_image());
    ret.set_real(a.get_real()-b.get_real());
    return ret;
}
void print(cmplx c)
{
    cout<<c.get_real()<<'+'<<c.get_image()<<'j';
}
void swp(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void swp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    emp e1;
    e1.set_age(20);
    e1.set_id(1);
    e1.set_name("mostafa");
    e1.set_salary(10000);
    e1.print();
    return 0;
}
