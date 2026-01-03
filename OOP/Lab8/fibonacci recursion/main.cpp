#include <bits/stdc++.h>

using namespace std;
vector<int>v(100,-1);
int fib(int n)
{
    if (n==0)return 0;
    if(n==1)return 1;
    if(v[n]!=-1)return v[n];
    return v[n] = (fib(n-1)+fib(n-2))%int(1e9)+7;
}
int main()
{
    for(int i=0;i<=1000000;i++)
    {
        cout<<"fib of ("<<i<<") is "<<fib(i)<<"\n";
    }
    return 0;
}
