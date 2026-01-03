#include <iostream>

using namespace std;

int main()
{
    cout<<"enter size of array\n";
    int n=0;
    cin>>n;
    int arr[50];
    cout<<"enter "<<n<<" numbers\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter number to search about\n";
    int srch=0;
    cin>>srch;
    int mn=arr[0],mx=arr[0],sum=0;
    bool found=0;
    for(int i=0;i<n;i++)
    {
        mn=min(mn,arr[i]);
        mx=max(mx,arr[i]);
        sum+=arr[i];
        if(srch==arr[i])found=1;
    }
    cout<<"sum is "<<sum<<"\n";
    cout<<"max number is "<<mx<<"\n";
    cout<<"min number is "<<mn<<"\n";
    if(found)cout<<"target number was found";
    else cout<<"target number was't found";
    return 0;
}
