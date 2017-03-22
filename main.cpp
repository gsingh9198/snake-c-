#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>
using namespace std;
bool tailprint;
const int width = 50;
const int height = 20;
bool gameOver;
int tailx[100], taily[100], tailn;
int x,y, foodx, foody, score=0;
enum direction{STOP = 0, RIGHT, LEFT, UP, DOWN} dir;

void launch()
{
    gameOver = false;
    x = 1;
    y = 1;
    foodx = width/2;
    foody = height/2;
}
void gameFrame()
{
    int i,j,k;
    cout << setw(30);
    system("cls");
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                cout << "#";
            }
            else if(i==y && j==x)
            {
                cout << "O";
            }
            else if(i==foody && j==foodx)
            {
                cout << "*";
            }
            else
            {
                tailprint = false;
                for(k=0; k<tailn; k++)
                    {
                        if(tailx[k]==j && taily[k]==i)
                        {
                            cout << "o";
                            tailprint = true;
                        }
                    }
                    if(!tailprint)
                    {
                        cout << " ";
                    }
            }

        }
        cout << endl;
        cout << setw(30);
    }
    cout << setw(30);
    cout << "SCORE: " << score;
}
void logic()
{
    int i,j;
    int xprev = tailx[0];
    int yprev = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for(i=1; i<tailn; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = xprev;
        taily[i] = yprev;
        xprev = prev2x;
        yprev = prev2y;
    }
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    if(x<0)
    {
        x=width-1;
    }
    else if(x>width-1)
    {
        x=0;
    }
    if(y<0)
    {
        y=height-1;
    }
    else if(y>height-1)
    {
        y=0;
    }
    if(x==foodx && y==foody)
    {
        score+=10;
        foodx = rand()%10+1;
        foody = rand()%10+1;
        tailn++;
    }
    for(i=0; i<tailn; i++)
    {
        if(x==tailx[i] && y==taily[i])
        {
            exit(0);
        }
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'z':
            exit(0);
            break;
        case 'p':
            system("pause");
        }
    }
}
int main()
{
    launch();
    while(!gameOver)
    {
        gameFrame();
        input();
        logic();
        Sleep(20);
    }
}
