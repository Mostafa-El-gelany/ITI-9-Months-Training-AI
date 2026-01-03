#include <iostream>

using namespace std;

int main()
{
    cout << "enter 5 numbers\n";
    int num,sum=0;
    for(int i=0;i<5;i++)
    {
        cin>>num;
        sum+=num;
    }
    cout<<"the sum is "<<sum;
    return 0;
}
