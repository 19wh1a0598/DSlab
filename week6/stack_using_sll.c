#include<stdio.h>
#include<stdlib.h>
int i,n;
struct node
{
	int data;
	struct node*link;
};
struct node* top = NULL,*cur,*next;
void push()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter value to insert\n");
	scanf("%d",&(cur->data));
	cur->link = top;
	top = cur;
}
void pop()
{
	cur = top;
	top = cur->link;
	cur->link = NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void display()
{
	if(top == NULL)
		printf("Stack underflow\n");
	else
	{
		next = top;
		while(next != NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}
void peek()
{
	printf("The top element of the stack is %d\n",top->data);
} 
int main()
{
	int ch;
	while(1)
	{
		printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();	
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:peek();
				break;
			case 5:exit(0);
		}
	}
}