#include <iostream>
#include <string.h>
using namespace std;

class person
{
    int id,age;
    char name[20];
public:
    person(int id=0,int age=0,char *name="undefined")
    {
        this->id=id;
        this->age=age;
        strcpy(this->name,name);
    }
    void set_id(int id)
    {
        this->id=id;
    }
    void set_age(int age)
    {
        this->age=age;
    }
    void set_name(char *name)
    {
        strcpy(this->name,name);
    }
    int get_id()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    char * get_name()
    {
        return name;
    }
    void print()
    {
        cout<<"id = "<<id<<"\n";
        cout<<"age = "<<age<<"\n";
        cout<<"name = "<<name<<"\n";
    }
};

class employee:public person
{
    int salary;
public:
    employee(int id=0,int age=0,char * name="undefined",int salary=0):person(id,age,name)
    {
        this->salary=salary;
    }
    void set_salary(int salary)
    {
        this->salary=salary;
    }
    int get_salary()
    {
        return salary;
    }
    void print()
    {
        person::print();
        cout<<"salary = "<<salary<<"\n";
    }
};

class student:public person
{
    char grade[20];
public:
    student(int id=0,int age=0,char * name="undefined",char *grade="undefined"):person(id,age,name)
    {
        strcpy(this->grade,grade);
    }
    void set_grade(char *grade)
    {
        strcpy(this->grade,grade);
    }
    char *get_grade()
    {
        return grade;
    }
    void print()
    {
        person::print();
        cout<<"grade = "<<grade<<'\n';
    }
};
int main()
{
    person p(1,25,"mostafa");
    p.print();

    cout<<"\n";

    employee e(2,30,"ahmed",10000);
    e.print();

    cout<<"\n";

    student s(3,18,"hossam","B+");
    s.print();


    return 0;
}
