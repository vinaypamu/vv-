/*10)

Write a function that accepts a month and year as input, and returns the number of days of the month as output. Print the number of days in a given month and year.*/
#include<stdio.h>
int day(int m,int y)
{
    	if(m==4||m==6||m==9||m==11)
		m=30;
	else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		m=31;
	else if((y%100!=0&&y%4==0)||y%400==0)
		m=29;
	else 
		m=28;
	return m;
}
int main()
{
	int m,y,a;
	printf("enter month and year");
	scanf("%d%d",&m,&y);
	if(y%100!=0&&y%4==0||y%400==0)
		a=366;
	else
		a=365;
	printf("%d days of the month and %d days of the year\n",day(m,y),a);
	return 0;
}

