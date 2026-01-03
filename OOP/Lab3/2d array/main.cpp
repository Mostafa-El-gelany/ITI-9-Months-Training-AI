#include <iostream>

using namespace std;

int main()
{
    int rows=0,cols=0,arr[100][100]={0},sum[100]={0},avg[100]={0};
    cout<<"enter number of rows\n";
    cin>>rows;
    cout<<"enter number of columns\n";
    cin>>cols;
    cout<<"enter numbers\n";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            sum[i]+=arr[i][j];
        }
    }
    for(int j=0;j<cols;j++)
    {
        for(int i=0;i<rows;i++)
        {
            avg[j]+=arr[i][j];
        }
        avg[j]/=rows;
    }
    cout<<"sum of rows is ";
    for(int i=0;i<rows;i++)
    {
        cout<<sum[i]<<' ';
    }
    cout<<"\naverage of columns is ";
    for(int i=0;i<cols;i++)
    {
        cout<<avg[i]<<' ';
    }
    return 0;
}
