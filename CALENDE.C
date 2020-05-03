#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define BKSP 8
#include<storm.h>
int FirstDayOfYear(int);
int FirstDayOfYear(int year)
{
 int first_day_of_year;
 first_day_of_year=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
 return first_day_of_year;
}
void main()
{
 int year,mth,days,wd=0,i,np;
 char *list_of_months[] = {"Janruary","February","March", "Aprail","May","June","July","August","September","October","November","December"};
 int list_of_day_in_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
 int first_day_of_month;
 clrscr();
 intro();
 clrscr();
 textbackground(BLACK);
 textcolor(GREEN);

 if((year%4==0&&year%100!=0)||year%400==0)
 list_of_day_in_months[1]=29;

 frame();
 gotoxy(24,12);
 cprintf("ENTER DESIRED YEAR :: ");
 scanf("%d",&year);
 first_day_of_month=FirstDayOfYear(year);

 for(mth=0;mth<12;mth++)
 {
  clrscr();
  printf("\n\n\n\n\n\n\n\n\t|.........................%s.........................|",list_of_months[mth]);
  printf("\n\n\t\t     MON  TUE  WED  THU  FRI  SAT  SUN\n\n\t\t   ");

  for(wd=0;wd<first_day_of_month;wd++)
  {
   printf("     ");


  }

  for(days=1;days<=list_of_day_in_months[mth];days++)
  {
    printf("%5d",days);
    wd++;
    if(wd>6)
    {
     printf("\n\t\t   ");
     wd=0;
    }
  }
  first_day_of_month=wd;
  gotoxy(40,23);
  cprintf("PRESS BACKSPACE FOR NEXT PAGE");
  frame();
  np=getch();
  if(np==BKSP)
  continue;
  else
  exit(0);
 }



 getch();
}