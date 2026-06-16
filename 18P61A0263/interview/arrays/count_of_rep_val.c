/*write a programe input is 10 20 30 40 10 40 50 20 10 30 40 
print a element how many times repeated
output: 10 is 3
20 is 2
30 is 2
40 is 3
50 is 1 */

#include<stdio.h>

int main()
{
	int size=0;
	printf("enter size of array");
	scanf("%d",&size);
	int array[size];
	for(int i=0;i<((sizeof(array)/sizeof(int)));i++)
	{
		printf("enter a value\n");
		scanf("%d",&(*(array+i)));
	}
	for(int i=0;i<((sizeof(array)/sizeof(int)));i++)
	{
		int count=1;
		for(int j=0;j<((sizeof(array)/sizeof(int)));j++)
		{
			if((array[i]==array[j])&&(i!=j))
			{
				if(i>j)
				{
					count=0;
					break;
				}
				else
					count++;
			}
		}
		if(count>=1)
		printf("%d is %d\n",array[i],count);
	}
	return 0;
}
