#include<stdio.h>
#include "GUI.h"
#include<conio.h>
#include "color.h"
#include "gotoxy.h"
#include<stdlib.h>
int posx=0;
int posy=0;
int sizes=6;
int prizex=0;
int prizey=0;
int score=0;
int lastx=0;
int lasty=0;
int time=120;
class node
{
public :
    int place;
    int nodex;
    int nodey;
    void createRand()      // for food , increasing speed , showing scores
    {
        time=time-4;             //increase speed when snake will eat food
        sizes++;                        
        score++;
        prizex=rand()%67;              //x coordinate of food
        if(prizex<10)
            prizex=13;
        prizey=rand()%24;				//y coordinate of food
        if(prizey<4)
            prizey=14;
        gotoxy(70, 8);               
        printf("Score = %d", score);     //scoreboard
        gotoxy(70, 9);
        printf("Snake = %d", sizes);
        gotoxy(prizex, prizey);
        printf("%c", 489);			 //placing food
    }
    void GameOver()           //game over menu
    {
        while(true)
        {
         gotoxy(20, 20);
        printf("\t\tGameOver, Your Score = %d", score);
        gotoxy(20, 21);
        printf("\t\tPress Any Key to Exit");
      getch();
            exit(EXIT_FAILURE);
        }
    }
    int update(int x, int y)
    {
        if(x>67||x<10||y>22||y<3)   //for checking if snake hit the wall
            GameOver();
            else if(x==prizex&&y==prizey)             //to check if snake ae the food
                createRand();
        gotoxy(lastx, lasty);       // algorithm for increase in the size of the snake
        printf("o");
        gotoxy(x, y);
      nodex=x;
      nodey=y;
        posx=x;
        posy=y;
        printf("@");
        lastx=x;
        lasty=y;
    }
    void CreateNode(int x, int y, int i)           //body of the snake
    {
        place=i;
        nodex=x;
        nodey=y;
        gotoxy(nodex, nodey);
        printf("%c", 489);
    }
    
    
    
    
    
    void Clear()            //clear the particular coordinate
    {
        gotoxy(nodex, nodey);
        printf(" ");
    }
};
class snake
{
    public:
        node n[100];
        int i=0;
    snake(int x, int y, int s)
    {
        n[0].createRand();                  		 // for food , increasing speed , showing scores      
        sizes=s;
        posx=x+5;
        posy=y;
        for(int i=0;i<sizes;i++)                      // this for loop is for the initialisation of body of snake for the first time
            n[i].CreateNode(x+i, y, i);
    }
    void move_right()
    {
        if(i==sizes)                            
        i=0;
        n[i].Clear();            //clear the particular coordinate
        n[i].update(++posx, posy);     //for moving and checking if game over or not
        i++;
        Sleep(time);                //increasing speed
        if(GetAsyncKeyState('W'))
            move_up();
       else if(GetAsyncKeyState('S'))
            move_down();
        else if(GetAsyncKeyState('D')){}
        else if(GetAsyncKeyState('A')){}
        move_right();
    }
    void move_left()
    {
        if(i==sizes)
        i=0;
        n[i].Clear();
        n[i].update(--posx, posy);
        i++;
        Sleep(time);
        if(GetAsyncKeyState('W'))
            move_up();
        else if(GetAsyncKeyState('S'))
            move_down();
        else if(GetAsyncKeyState('D')){}
        else if(GetAsyncKeyState('A')){}
        move_left();
    }
    void move_up()
    {
        if(i==sizes)
        i=0;
        n[i].Clear();
        n[i].update(posx, --posy);
        i++;
        Sleep(time);
        if(GetAsyncKeyState('D'))
            move_right();
        else if(GetAsyncKeyState('A'))
            move_left();
        else if(GetAsyncKeyState('W')){}
        else if(GetAsyncKeyState('S')){}
        move_up();
    }
    void move_down()
    {
        if(i==sizes)
        i=0;
        n[i].Clear();
        n[i].update(posx, ++posy);
        i++;
        Sleep(time);
        if(GetAsyncKeyState('D'))
            move_right();
        else if(GetAsyncKeyState('A'))
            move_left();
        else if(GetAsyncKeyState('W')){}
        else if(GetAsyncKeyState('S')){}
        move_down();
    }
};

int main()
{

    SetColor(15);         //setting color of words
printf("-----------------------------------------------------------------------------\n");
printf("----------------------------------------Snake-Mania---------------------------\n");
   hidecursor();
    GetFrame();				//frame of play area
    gotoxy(70, 19);
printf("Developers : ");        
gotoxy(69, 20);
printf("Kunal");
gotoxy(69, 21);
printf("KunalGaurav");
gotoxy(69, 22);
printf("HimanshuGidwani");
SetColor(10);
snake s(10, 10, 7);                //storing value of coordinates of snake and its initial                    
s.move_right();                    //program will start with snake facing in right direction
    return 0;
}
