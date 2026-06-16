/* user input is 1 mean add node 2 mean print list 3 mean delete 4 mean reverse 5 mean exit*/
#include<stdio.h>
#include<stdlib.h>
typedef struct stud{
char array[10];
struct stud * ptr;
}stud;

void add(stud **head,stud **next)
{
	stud *ptr=(stud *)malloc(sizeof(stud));
	if(ptr==NULL)
	{
		printf("run is outoff stack\n");
		return ;
	}
	else
	{
		printf("enter string value\n");
		scanf("%9s",ptr->array);
		ptr->ptr=NULL;
	}
	if(*head==NULL)
	{
		*head=ptr;
		*next=ptr;
	}
	else
	{
		(*next)->ptr=ptr;
		*next=ptr;
	}
};

void print(stud *head)
{
if(head==NULL)
{
	printf("stack is empty\n");
return ;
}
else
{
while(head!=NULL)
{
	printf("%s",head->array);
	head=head->ptr;
	if(head!=NULL)
		printf("->");
}
printf("\n");
}
}

void delete(stud **head,stud** next)
{
	stud * ptr=*head;
	if(ptr==NULL)
	{
		printf("stack is empty\n");
		return ;

	}
	else 
	{
		if(ptr->ptr==NULL)
		{
		free(ptr);
		*head=NULL;
		*next=NULL;
		}
		else
		{
		while((ptr->ptr->ptr)!=NULL)
		{ ptr=ptr->ptr;
		};
		*next=ptr;
		free(ptr->ptr);
		(*next)->ptr=NULL;
		}
	}

}

void reverse(stud **head,stud ** next)
{
	stud *current=*head,*nxt=NULL,*pre=NULL;
	if(*head==NULL)
		printf("nothing to reverse\n");
	else if ((*head)->ptr==NULL)
		printf("list has one node only\n");
	else
	{
		while(current!=NULL)
		{
			nxt=current->ptr;
			current->ptr=pre;
			pre=current;
			current=nxt;
		}
		*head=pre;
	}
	
}

int main()
{
	stud *head=NULL,*next=NULL;
int a=0;
while(1)
{
	printf("enter 1-add 2-print 3-delete 4-reverse 5-exit\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			add(&head,&next);
			break;
		case 2:
			print(head);
			break;
		case 3:
			delete(&head,&next);
			break;
		case 4:	
			reverse(&head,&next);
			break;
		case 5:
			return 0;
			break;
	};
}
}
