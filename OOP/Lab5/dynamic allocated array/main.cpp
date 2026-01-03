#include <iostream>

using namespace std;

int main()
{
    cout<<"enter size of array\n";
    int n=0;cin>>n;
    int *arr=new int[n];
    if(arr==nullptr)
    {
        cout<<"something wrong happened";
        return 0;
    }
    cout<<"enter numbers\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"numbers are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
