#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char c;
    bool flag = 1;
    do{
        system("cls");
        cout<<"new\ndesplay\nexit\n";
        cout<<"enter (n,d,e)\n";
        c=getch();
        switch(c){
    case 'n':
    case 'N':
        cout<<"new item was added\n";
        break;
    case 'd':
    case 'D':
        cout<<"display item was selected\n";
        break;
    case 'e':
    case 'E':
    case 27 :
        cout<<"exit item was selected\n";
        flag=0;
        break;
        }
        getch();
    }while(flag);
    return 0;
}
