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
    cout<<"enter odd size of the box\n";
    int sz=0,dist=3;cin>>sz;
    int cur_row=1,cur_col=sz/2+1,cur_num=1;
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
        {
            textattr(i+1);
            gotoxy(cur_row*dist,cur_col*dist);
            cur_col--;
            cur_row--;
            if(cur_col==0)cur_col+=sz;
            if(cur_row==0)cur_row+=sz;
            cout<<cur_num++;
        }
        cur_col++;
        if(cur_col>sz)cur_col-=sz;
        cur_row+=2;
        if(cur_row>sz)cur_row-=sz;
    }
    return 0;
}
