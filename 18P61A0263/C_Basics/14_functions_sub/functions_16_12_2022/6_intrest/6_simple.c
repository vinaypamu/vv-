/*6)
 * Write a function that takes principle, rate of interest and time in months as input arguments, and returns the total amount to be repayed, after calculation of simple interest.*/
#include"head.h"
int main()
{
	int p,m;
	float i;
	printf("enter principle months intrest");
	scanf("%d%d%f",&p,&m,&i);
	printf("%f is totall repay",simple(p,m,i));
	return 0;
}
