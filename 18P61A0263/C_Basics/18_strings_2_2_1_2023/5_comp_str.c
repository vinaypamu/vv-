// compare arrays find  big nad small arrays.
#include<stdio.h>
int main()
{
	int s2=0;
	char s[50],s1[50];
	printf("enter 1st string\n ");
	scanf(" %49[^\n]s",s);
	printf("enter 2nd string \n");
	scanf(" %49[^\n]s",s1);
       int m(char s[],char s1[]);
       s2=m(s,s1);
       if(s2==0)
	       printf("%s and %s are equal",s,s1);
       else if(s2>0)
	       printf("%s is big %s is small",s,s1);
       else if(s2<0)
	       printf("%s is small %s is big",s,s1);
       return 0;
}
int m(char s[],char s1[])
{
	int i=0;
	for(i=0;((s[i]!=0)||(s1[i]!=0));i++)
	{
		if(s[i]!=s1[i])
			return (s[i]-s1[i]);
	}
	return s[i]-s1[i];
}
