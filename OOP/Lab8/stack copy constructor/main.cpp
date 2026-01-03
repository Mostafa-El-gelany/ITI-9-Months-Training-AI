#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

class stk
{
    int *arr,sz,tos;
public:
    stk(int sz)
    {
        arr=new int[sz];
        this->sz=sz;
        tos=-1;
    }
    ~stk()
    {
        delete[]arr;
    }
    stk(stk &s)
    {
        sz=s.sz;
        tos=s.tos;
        arr=new int[sz];
        for(int i=0;i<=tos;i++)
            arr[i]=s.arr[i];
        cout<<"stack copied successfully\n";
    }
    int pop(int &n)
    {
        if(tos==-1)
        {
            cout<<"********************\n";
            cout<<"stack is empty\n";
            cout<<"********************\n";
            return  0;
        }
        n=arr[tos--];
        return 1;

    }
    void push(int num)
    {
        if(tos==sz-1)
        {
            cout<<"********************\n";
            cout<<"stack is full\n";
            cout<<"********************\n";
        }
        else
        {
            arr[++tos]=num;
            cout<<num<<" pushed successfully\n";
        }
    }
};

int main()
{
    textattr(3);
    int a;
    stk ss(5);


    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.push(5);
    ss.push(6);
    textattr(10);
    stk s(ss);

    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";

    textattr(7);


    return 0;
}
