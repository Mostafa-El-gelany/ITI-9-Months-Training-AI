#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char c,last_chr=' ';
    int words=0,chars=0;
    cout<<"enter a sentece\n";
    do{
        c=getch();
        if(c!=' '&&c!=13)
        {
            chars++;
            if(last_chr==' ')words++;
        }
        last_chr=c;
        if(c!=13)cout<<c;
    }while(c!=13);
    cout<<"\n";
    cout<<"number of words is "<<words<<"\n";
    cout<<"number of chars is "<<chars;
    return 0;
}
