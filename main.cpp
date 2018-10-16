#include<iostream>
#include<vector>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<stdio.h>
using namespace std;

char items[]={'A','B','G','M','P','L','A','R','E','C'};
int score=0;
class Snake;
class Food;
class Boundary
{
protected:
    char Board[32][52];
public:
    Boundary()
    {
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<52;j++)
            {
                if(i==0 || j==0 || i==31 || j==51)
                    Board[i][j]='#';
                else
                    Board[i][j]=' ';
            }
        }
    }
    void print()
    {
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<52;j++)
            {
                cout<<Board[i][j];
            }
            cout<<endl;
        }
    }
    friend class Food;
    friend class Snake;
};
class Food
{
public:
        int x,y,f_x;
    void popup(Boundary &Border)
    {
        srand(time(0));
        f_x = rand() % 10;
        x = rand() % 20 + 1;
        y = rand() % 30 + 1;
        Border.Board[x][y] = items[f_x];
        Border.print();
    }
};
class Snake
{
protected:
    vector<char> Body;
    int x,y,x_e,y_e;
public:
    Snake()
    {
        x=5,y=6;
        x_e=5,y_e=4;
    }
    void Birth(Boundary &Border)
    {
        Body.push_back('H');
        Body.push_back('*');
        Body.push_back('*');
        for(int i=y;i>3;i--)
            Border.Board[x][i] = Body[6 - i];
    }
    void move(Boundary &Border,Food &F)
    {
        char choice,prev_choice;
            choice=_getch();
        while(1)
        {
            if(kbhit())
            {
                    choice=_getch();
                    if(choice == ' ')
                    {
                        system("pause");
                    }
                if((prev_choice == 'w' && choice == 's') || (prev_choice == 's' && choice == 'w') || (prev_choice == 'a' && choice == 'd') || (prev_choice=='d' && choice=='a'))
                {
                    choice=prev_choice;
                }
            }
            switch(choice)
            {
            case 'd':
                if(Border.Board[x][y-1] == '*')
                {
                    Border.Board[x][y+1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y-1];
                    y++;
                }
                else if(Border.Board[x-1][y] == '*')
                {
                    Border.Board[x][y+1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x-1][y];
                    y++;
                }
                else if(Border.Board[x+1][y] == '*')
                {
                    Border.Board[x][y+1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x+1][y];
                    y++;
                }
                else if(Border.Board[x][y+1]== '*')
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(x == 0 || x==31 || y==51 || y==0)
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(F.x == x && F.y == y)
                {
                    Body.insert(Body.begin(),'*');
                    Border.Board[x][y+1] = 'H';
                    Border.Board[x][y] = '*';
                    y++;
                    score+=2;
                    F.popup(Border);
                }
                else
                {
                    Border.print();
                    Sleep(10);
                    system("CLS");
                }
                break;
            case 'a':
                if(Border.Board[x][y+1] == '*')
                {
                    Border.Board[x][y-1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y+1];
                    y--;
                }
                else if(Border.Board[x-1][y] == '*')
                {
                    Border.Board[x][y-1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x-1][y];
                    y--;
                }
                else if(Border.Board[x+1][y] == '*')
                {
                    Border.Board[x][y-1] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x+1][y];
                    y--;
                }
                else if(Border.Board[x][y-1]== '*')
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(x == 0 || x==31 || y==51 || y==0)
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(F.x == x && F.y == y)
                {
                    Body.insert(Body.begin(),'*');
                    Border.Board[x][y-1] = 'H';
                    Border.Board[x][y] = '*';
                    y--;
                    score+=2;
                    F.popup(Border);
                }
                else
                {
                    Border.print();
                    Sleep(10);
                    system("CLS");
                }
                break;
            case 's':
                if(Border.Board[x][y-1] == '*')
                {
                    Border.Board[x+1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y-1];
                    x++;
                }
                else if(Border.Board[x-1][y] == '*')
                {
                    Border.Board[x+1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x-1][y];
                    x++;
                }
                else if(Border.Board[x][y+1] == '*')
                {
                    Border.Board[x+1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y+1];
                    x++;
                }
                else if(Border.Board[x+1][y]== '*')
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(x == 0 || x==31 || y==51 || y==0)
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(F.x == x && F.y == y)
                {
                    Border.Board[x+1][y] = 'H';
                    Border.Board[x][y] = '*';
                    x++;
                    score+=2;
                    F.popup(Border);
                }
                else
                {
                    Border.print();
                    Sleep(10);
                    system("CLS");
                }
                break;
            case 'w':
                if(Border.Board[x][y-1] == '*')
                {
                    Border.Board[x-1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y-1];
                    x--;
                }
                else if(Border.Board[x+1][y] == '*')
                {
                    Border.Board[x-1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x+1][y];
                    x--;
                }
                else if(Border.Board[x][y+1] == '*')
                {
                    Border.Board[x-1][y] = Border.Board[x][y];
                    Border.Board[x][y] = Border.Board[x][y+1];
                    x--;
                }
                else if(Border.Board[x-1][y]== '*')
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(x == 0 || x==31 || y==51 || y==0)
                {
                    cout<<"GAME OVER"<<endl;
                    exit(0);
                }
                if(F.x == x && F.y == y)
                {
                    Border.Board[x-1][y] = 'H';
                    Border.Board[x][y] = '*';
                    x--;
                    score+=2;
                    F.popup(Border);
                }
                else
                {
                    Border.print();
                    Sleep(10);
                    system("CLS");
                }
                break;
            case '0':
                cout<<"GAME ENDED"<<endl;
                cout<<"WELL PLAYED"<<endl;
                cout<<"YOUR SCORE IS : "<<score<<endl;
                exit(0);
                break;
            default:
                continue;
            }
            Border.Board[x_e][y_e] = ' ';
            if(Border.Board[x_e][y_e-1] == '*')
                y_e--;
            else if(Border.Board[x_e][y_e+1] == '*')
                y_e++;
            else if(Border.Board[x_e-1][y_e] == '*')
                x_e--;
            else if(Border.Board[x_e+1][y_e] == '*')
                x_e++;
                prev_choice = choice;
        }
    }
};
int main()
{
    int choice;
    Boundary Border;
    Food F;
    Snake S;
    S.Birth(Border);
    cout<<"\t\t\t\t\t\tWELCOME TO SNAKE GAME"<<endl;
    Menu:
    cout<<"ENTER 1 TO START"<<endl;
    cout<<"ENTER 0 TO END"<<endl;
    cout<<"ENTER SPACE TO PAUSE"<<endl;
    cout<<"FOR KNOW ABOUT CONTROLLS ENTER 5"<<endl;
    cin>>choice;
    if(choice==1)
    {
        F.popup(Border);
        S.move(Border,F);
    }
    else if(choice == 5)
    {
        cout<<"D -> FORWARD"<<endl;
        cout<<"A -> BACKWARD"<<endl;
        cout<<"W -> UP"<<endl;
        cout<<"S -> DOWN"<<endl<<endl;
        goto Menu;
    }
    else
        exit(0);
    return 0;
}
