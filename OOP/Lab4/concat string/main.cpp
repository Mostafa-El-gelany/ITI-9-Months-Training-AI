#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
    char s1[20]="",s2[20]="",s3[40]="";
    cout<<"enter first sting\n";
    gets(s1);
    cout<<"enter second string\n";
    gets(s2);
    strcat(s3,s1);
    strcat(s3," ");
    strcat(s3,s2);
    cout<<"final string is: ";
    cout<<s3;
    return 0;
}
