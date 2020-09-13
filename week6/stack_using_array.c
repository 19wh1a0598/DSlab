#include<stdio.h>
#include<stdlib.h>
# define maxsize 5
int a[maxsize],top=-1;
void push(int item)
{
	top++;
	a[top] = item;
}
int pop()
{
	return(a[top--]);

}
int isfull()
{
	if(top == maxsize-1)
		return 1;
	else
		return 0;
}
int isempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}
int peek()
{
	return(a[top]);
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
		printf("%d ",a[i]);
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
					printf("Stack overflow\n");
				else
				{
					printf("Enter  data to push\n");
					scanf("%d",&x);
					push(x);
				}
				break;
			case 2: if(isempty())
					printf("Stack underflow\n");
				else
				{
					x = pop();
					printf("Deleted element is %d\n",x);
				}
				break;
			case 3: display();
				break;
			case 4: printf("Top element in stack is %d\n",peek());
				break;
			case 5:exit(0);
		}
	}
} 
