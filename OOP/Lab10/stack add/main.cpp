#include <iostream>
#include <string.h>
using namespace std;

class stk
{
    int* arr, sz, tos;
public:
    stk(int sz)
    {
        arr = new int[sz];
        this->sz = sz;
        tos = -1;
    }
    ~stk()
    {
        delete[]arr;
    }
    stk(stk& s)
    {
        sz = s.sz;
        tos = s.tos;
        arr = new int[sz];
        for (int i = 0; i <= tos; i++)
            arr[i] = s.arr[i];
        cout << "stack copied successfully\n";
    }
    int pop(int& n)
    {
        if (tos == -1)
        {
            cout << "\n";
            cout << "stack is empty\n";
            cout << "\n";
            return  0;
        }
        n = arr[tos--];
        return 1;

    }
    void push(int num)
    {
        if (tos == sz - 1)
        {
            cout << "\n";
            cout << "stack is full\n";
            cout << "\n";
        }
        else
        {
            arr[++tos] = num;
            //cout<<num<<" pushed successfully\n";
        }
    }
    int get_size()
    {
        return tos + 1;
    }
    int get_top()
    {
        return arr[tos];
    }
};

void fun2(char* arr, int& l, int& r, int& next_idx, int& sign, int& num, stk& numbers, stk& operators, int op,int &active_num)
{
    if (sign==1)
    {
        sign =-sign;
        num = -num;
    }
    numbers.push(num);
    active_num=0;
    if (operators.get_size() > 0)
    {
        if (operators.get_top() == '*')
        {
            int a = 0, b = 0, c = 0;
            numbers.pop(a);
            numbers.pop(b);
            numbers.push(a * b);
            operators.pop(c);
        }
        else if (operators.get_top() == '/')
        {
            int a = 0, b = 0, c = 0;
            numbers.pop(a);
            numbers.pop(b);
            numbers.push(b / a);
            operators.pop(c);
        }
    }
    operators.push(op);
}

int fun1(char* arr, int l, int r, int& next_idx)
{
    stk numbers(200), operators(200);
    int num = 0, sign = -1,active_num=0;
    for (int i = l; i < r; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            if (active_num==0)
            {
                active_num=1;
                num = arr[i] - '0';
            }
            else
            {
                num *= 10;
                num += arr[i] - '0';
            }
        }
        else if (arr[i] == '-')
        {
            fun2(arr, l, r, next_idx, sign, num, numbers, operators, '+',active_num);
            sign =-sign;

        }
        else if (arr[i] == '(')
        {
            int idx = 0;
            num = fun1(arr, i + 1, r, idx);
            active_num=1;
            i = idx;
        }
        else if (arr[i] == ')')
        {
            next_idx = i;
            break;
        }
        else
        {
            fun2(arr, l, r, next_idx, sign, num, numbers, operators, arr[i],active_num);
        }
    }
    if (active_num)
    {
        if (sign==1)
        {
            sign =-sign;
            num = -num;
        }
        numbers.push(num);
    }
    while (operators.get_size() > 0)
    {
        int a = 0, b = 0, c = 0;
        numbers.pop(a);
        numbers.pop(b);
        operators.pop(c);
        if (c == '+')numbers.push(a + b);
        else if (c == '-') numbers.push(b - a);
        else if (c == '*')numbers.push(a * b);
        else numbers.push(b / a);

    }
    return numbers.get_top();
}

void implace(char *arr, char c,int idx,int &sz)
{
    if(idx<sz)
        for(int i=sz-1;i>=idx;i--)
            arr[i+1]=arr[i];
    arr[idx]=c;
    sz++;
}


void clean(char *arr,int &sz)
{
    char arr2[200];
    int idx=0;
    for(int i=0;i<200;i++)
    {
        if(arr[i]==' ')
        {
            sz--;
            continue;
        }
        arr2[idx++]=arr[i];
        if(arr[i]=='\0')break;
    }
    arr2[idx]='\0';

    strcpy(arr,arr2);

    implace(arr,'(',0,sz);
    implace(arr,')',sz,sz);
    for(int i=1;i<sz;i++)
    {
        if(arr[i]=='-'&&arr[i-1]=='(')implace(arr,'0',i,sz);
    }

}


int main()
{


    char arr[200];
    gets(arr);

    int sz=0;
    for(int i=0;i<200;i++)
    {
        if(arr[i]=='\0')
        {
            sz=i;
            break;
        }
    }

    clean(arr,sz);

    cout << fun1(arr, 0, sz, sz);


    return 0;
}

/*


((10*(2+(3*(2+2))))/4)
35






(((5+3)*(7-(4/2))+(6/(3))))
42





(10-(3*(2+1)))
1




(2+6* 3+5- (3*14/7+2)*5)+3
-12

*/
