/*Modify the calculator program - with functions ,Add(),Sub(),Mul(),Div(),Mod(). Each function should take the inputs as parameters and return the result as output.
 * Hint: int add(int , int);
 * int sub (int, int);*/
#include<stdio.h>
int sum(int x,int y)
{
	x=x+y;
	return x;
}
int sub(int x, int y)
{
	x=x-y;
	return x;
}
int mul(int x, int y)
{
	x=x*y;
	return x;
}
int div(int x, int y)
{
	x=x/y;
	return x;
}
int mod(int x, int y)
{
	x=x%y;
	return x;
}
int main()
{
	int a,b;
	char c;
	scanf("%d %c%d",&a,&c,&b);
	switch(c)
	{
		case'+':printf("%d is sum of two num",sum(a,b));
			break;
		case'-':printf("%d is sub of two num",sub(a,b));
			break;
		case'*':printf("%d is mul of two num",mul(a,b));
			break;
		case'/':printf("%d is div of two num",div(a,b));
			break;
		case'%':printf("%d is mode of two num",mod(a,b));
			break;
	}
	return 0;
}







