#include <iostream>

using namespace std;

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
            arr[++tos]=num;
    }
};

class que
{
    int *arr,sz,rear;
public:
    que(int sz)
    {
        rear=-1;
        arr=new int[sz];
        this->sz=sz;
    }
    ~que()
    {
        delete[]arr;
    }

    void enqueue(int n)
    {
        if(rear==sz-1)
        {
            cout<<"********************\n";
            cout<<"queue is full\n";
            cout<<"********************\n";
        }
        else arr[++rear]=n;
    }
    int dequeue(int &n)
    {
        if(rear==-1)
        {
            cout<<"********************\n";
            cout<<"queue is empty\n";
            cout<<"********************\n";
            return 0;
        }
        else
        {
            n=arr[0];
            for(int i=0;i<rear;i++)
            {
                arr[i]=arr[i+1];
            }
            rear--;
            return 1;
        }
    }
};

int main()
{

    int a;
    stk s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n";
    cout<<s.pop(a)<<' '<<a<<"\n\n\n";

    que q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout<<q.dequeue(a)<<' '<<a<<"\n";
    cout<<q.dequeue(a)<<' '<<a<<"\n";
    cout<<q.dequeue(a)<<' '<<a<<"\n";
    cout<<q.dequeue(a)<<' '<<a<<"\n";
    cout<<q.dequeue(a)<<' '<<a<<"\n";
    cout<<q.dequeue(a)<<' '<<a<<"\n";



    return 0;
}
