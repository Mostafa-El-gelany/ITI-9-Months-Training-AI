#include <iostream>

using namespace std;

int main()
{
    int x,y,ans=1;
    cout<<"enter the base\n";
    cin>>x;
    cout<<"enter the power\n";
    cin>>y;
    for(int i=0;i<y;i++)
    {
        ans*=x;
    }

    cout<<"the answer is "<<ans;
    return 0;
}
