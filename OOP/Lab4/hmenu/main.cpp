#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

int main()
{
    int hline=0;
    char arr[3][20]={"new","display","exit"};
    char c=' ';
    bool flag = 1;
    do{
        system("cls");
        for(int i=0;i<3;i++)
        {
            if(i==hline)textattr(0x03);
            cout<<arr[i]<<"\n";
            textattr(0x07);
        }
        c=getch();
        switch(c){
    case -32:
        c=getch();
        switch(c){
        case 72:
            hline--;
            if(hline==-1)hline=2;
            break;
        case 80:
            hline++;
            if(hline==3)hline=0;
            break;
            }
            break;
        case 13:
        switch(hline){
        case 0:
            cout<<"New item was selected\n";
            getch();
            break;
        case 1:
            cout<<"display item was selected\n";
            getch();
            break;
        case 2:
            cout<<"exit item was selected\n";
            flag=0;
            getch();
            break;
            }
        }

    }while(flag);

    return 0;
}
