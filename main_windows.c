#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "helper_windows.h"
#include<unistd.h>
#define KRED  "\x1B[31m"
int level;
int scan;
char b;
char s[10][10];
char type[10];
int flag=0;
int counter=0;
void gotoxy(int x,int y)
{
  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void clrscr()
{
  system("@cls||clear");
}
  int j=9;
  int i=0;
void my_callback_on_key_arrival(char c)
{ 
  // Just for test, remove this line
  
      while(s[j][i]==c)
      {
        s[j][i]='*';
        i++;
      }
     if(s[j][i]=='\0')
      {
        j--;
        i=0;
        counter ++;
      }
  
  
  // Do something with this c
}

int main()
{
  // Menu stuff goes here
  HANDLE thread_id = start_listening(my_callback_on_key_arrival);
  // The rest of your main code goes here
printf("enter your level:1,2,3\n");
scanf("%d",&scan);
clrscr();
if(scan==1)
{
  level=3;
}
if(scan==2)
{
  level=2;
}
if(scan==3)
{
  level=1;
}
FILE*kalamat=fopen("kalamat.txt","r");
   for(int j=0;j<10;j++)
   {fscanf(kalamat,"%s",s[j]);} 
  for(int i=0;i<120;i++)
  {
  gotoxy(i,29);
  printf("#");
  }

   for(int i=0;i<20+counter;i++)
   {   gotoxy(95,2);
       printf("level=%d",scan);
        gotoxy(15,2);
       printf("score=%d",counter);
      gotoxy(55,i);
   for(int j=0;j<10;j++)
   { gotoxy(55,i+j);
     printf("%s",s[j]);
   }
    sleep(level);
   if(i<19+counter)
   {
     clrscr();
   }
   for(int i=0;i<120;i++)
  {
  gotoxy(i,29);
  printf("#");
  }
  if(i>=19&&counter==i-19)
  {
    clrscr();
    gotoxy(55,15);
    printf("GAME OVER");
  }
  if(counter==10)
  { clrscr();
    gotoxy(55,15);
    printf("victory!!!!!");
    i=100;
  }
   }
   
    
   
  WaitForSingleObject(thread_id, INFINITE);
  return 0;
}
