#include <iostream>

using namespace std;

int power(int base,int pow)
{
    int ans=1;
    for(int i=0;i<pow;i++)
    {
        ans*=base;
    }
    return ans;
}

int factorial(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}

int reverse_int(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans*=10;
        ans+=n%10;
        n/=10;
    }
    return ans;
}
int main()
{

    return 0;
}
