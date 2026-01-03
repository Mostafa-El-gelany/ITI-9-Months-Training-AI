#include <iostream>

using namespace std;

int main()
{
    cout<<"enter your degree\n";
    int n;cin>>n;
    cout<<"your grade is ";
    if(n>=85)cout<<"A";
    else if(n>=75)cout<<"B";
    else if(n>=65)cout<<"C";
    else if(n>=50)cout<<"D";
    else if(n<50&&n>=0)cout<<"F";
    else cout<<"invalid degree";

    return 0;
}
