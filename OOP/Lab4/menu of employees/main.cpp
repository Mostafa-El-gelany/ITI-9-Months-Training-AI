#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
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

struct emp{
    int id;
    char name[20];
    int age;
};

int main()
{
    emp employees[20];
    int cur_idx=0;
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
            if(cur_idx==20)
            {
                cout<<"array is full\n";
                getch();
                break;
            }
            cout<<"enter employee's id\n";
            cin>>employees[cur_idx].id;
            cout<<"enter employee's name\n";
            cin.ignore();
            gets(employees[cur_idx].name);
            cout<<"enter employee's age\n";
            cin>>employees[cur_idx].age;
            cout<<"employee added successfully\n";
            cur_idx++;
            getch();
            break;
        case 1:
            if(cur_idx==0)
            {
                cout<<"no employees added yet\n";
                getch();
                break;
            }
            for(int i=0;i<cur_idx;i++)
            {
                cout<<"********************************\n";
                cout<<"id is "<<employees[i].id<<"\n";
                cout<<"name is "<<employees[i].name<<"\n";
                cout<<"age is "<<employees[i].age<<"\n";
                cout<<"********************************\n";

            }
            getch();
            break;
        case 2:
            cout<<"exit was selected\n";
            flag=0;
            getch();
            break;
            }
        }

    }while(flag);

    return 0;
}
