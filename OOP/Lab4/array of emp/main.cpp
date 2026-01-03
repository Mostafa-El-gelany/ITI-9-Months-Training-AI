#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct emp{
    int id;
    char name[20];
    int age;
};

int main()
{
    int n=0;
    cout<<"enter number of employees\n";
    cin>>n;
    emp arr[n];
    for(int i=0;i<n;i++)
    {

        cout<<"enter employee's id\n";
        cin>>arr[i].id;

        cout<<"enter employee's name\n";
        cin>>gets(arr[i].name);

        cout<<"enter employee's age\n";
        cin>>arr[i].age;

    }

    for(int i=0;i<n;i++)
    {
        cout<<"********************************\n";
        cout<<"id is "<<arr[i].id<<"\n";
        cout<<"name is "<<arr[i].name<<"\n";
        cout<<"age is "<<arr[i].age<<"\n";
        cout<<"********************************\n";
    }
    return 0;
}
