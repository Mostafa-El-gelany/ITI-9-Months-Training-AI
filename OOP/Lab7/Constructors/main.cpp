#include <iostream>
#include <string.h>

using namespace std;

class emp{
    int id=0,age=0;
    char name[20]="";
    float salary=0;

public:
    emp(int id,char* name)
    {
        this->id=id;
        strcpy(this->name, name);
    }

    emp(int id,char* name,int age)
    {
        this->id=id;
        strcpy(this->name, name);
        this->age=age;
    }
    emp(int id,char* name,int age,float salary)
    {
        this->id=id;
        strcpy(this->name, name);
        this->age=age;
        this->salary=salary;
    }
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
        cout<<"************************\n";
        cout<<"employee's id is "<<id<<"\n";
        cout<<"employee's name is "<<name<<"\n";
        cout<<"employee's age is "<<age<<"\n";
        cout<<"employee's salary is "<<salary<<"\n";
        cout<<"************************\n";

    }
};

class cmplx{
    int real=0,img=0;
public:
    cmplx(int real=0,int img=0)
    {
        this->real=real;
        this->img=img;
    }
    void set_real(int _real)
    {
        real=_real;
    }
    void set_img(int _img)
    {
        img=_img;
    }

    int get_real()
    {
        return real;
    }
    int get_img()
    {
        return img;
    }
    void print()
    {
        cout<<real<<'+'<<img<<'j'<<"\n";
    }
    void add(cmplx c)
    {
        real+=c.real;
        img+=c.img;
    }
};



int main()
{
    emp e1(1,"mostafa"),e2(2,"ahmed",30),e3(3,"hassan",25,10000);
    e1.print();
    e2.print();
    e3.print();
    cout<<"\n";

    cmplx c1,c2(6),c3(7,3);

    c1.print();
    c2.print();
    c3.print();
    return 0;
}
