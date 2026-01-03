#include <iostream>

using namespace std;

void swp(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
    int x=0,y=0;
    cin>>x>>y;
    swp(&x,&y);
    cout<<x<<' '<<y;
    return 0;
}
