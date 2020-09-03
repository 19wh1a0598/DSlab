#include<stdio.h>
#include<stdlib.h>
int i,n;
struct node
{
	int data;
	struct node*link;
};
struct node*head = NULL,*tail = NULL,*cur,*prev,*next;
void create()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("Enter current node data\n");
		scanf("%d",&(cur->data));
		cur->link = NULL;
		if(head == NULL)
			head=tail=cur;
		else
		{
			tail->link = cur;
			tail = cur;
		}
	}
}
void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter value to insert\n");
	scanf("%d",&(cur->data));
	cur->link = head;
	head = cur;
}
void insert_at_position()
{
	int pos,c;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&(cur->data));
	printf("Enter the position");
	scanf("%d",&pos);
	c = 1;
	next = head;
	while(c < pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = cur;
	cur->link = next;
}
void insert_after()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the value after which data to be inserted\n");
	scanf("%d",&(cur->data));
	printf("enter the value\n");
	scanf("%d",&value);
	next = head;
	while(next->data != value && next != NULL)
		next = next->link;
	cur->link = next->link;
	next->link = cur;
}
void insert_before()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the value before which data to be inserted\n");
	scanf("%d",&(cur->data));
	printf("enter the value\n");
	scanf("%d",&value);
	next = head;
	while(next->data != value && next != NULL)
	{
		prev = next;
		next = next->link;
	}
	prev->link = cur;
	cur->link = next;
}
void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter value to be inserted\n");
	scanf("%d",&(cur->data));
	cur->link = NULL;
	tail->link = cur;
	tail = cur;
}
void traversal()
{
	if(head == NULL)
		printf("Link is empty");
	else
	{
		next = head;
		while(next != NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}
void delete_at_begin()
{
	cur = head;
	head = cur->link;
	cur->link = NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void delete_at_end()
{
	cur = head;
	while(cur->link != tail)
		cur = cur->link;
	cur->link = NULL;
	next = tail;
	printf("Deleted element is %d\n",next->data);
	free(next);
	tail = cur;
}
void delete_at_position()
{
	int c,pos;
	next = head;
	c = 1;
	printf("Enter the position to delete\n");
	scanf("%d",&pos);
	while(c < pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = next->link;
	printf("Deleted element is %d\n",next->data);
	next->link = NULL;
	free(next);
}
void delete_before()
{
	int value;
	printf("Enter value before which data to be deleted\n");
	scanf("%d",&value);
	next = head;
	while(next->link->data != value)
	{
		prev = next;
		next = next->link;
	}
	prev->link = next->link;
	next->link = NULL;
	printf("%d\n",next->data);
	free(next);
}
void delete_after()
{
	int value;
	printf("Enter value after which data to be deleted\n");
	scanf("%d",&value);
	next = head;
	while(next->data != value)
	{
		prev = next;
		next = next->link;
	}
	prev = next->link;
	next->link = prev->link;
	printf("Deleted element is %d\n",prev->data);
	prev->link = NULL;
	free(prev);
}
void sorting()
{
	struct node*p1,*p2,*t;
	p1 = head;
	int i,c=0;
	while(p1 != NULL)
	{
		c++;
		p1 = p1->link;
	}
	for(i=0;i<c;i++)
	{
		p2 = head;
		while(p2->link != NULL)
		{
			if(p2->data > p2->link->data)
			{
				t = p2->data;
				p2->data = p2->link->data;
				p2->link->data = t;
			}
			p2 = p2->link;
		}
	}
}
void reverse(struct node* head)
{
	if(head != NULL)
	{
		reverse(head->link);
		printf("%d->\n",head->data);
	}
}
void search()
{
	int value,flag=0,c=0;
	printf("enter value to search\n");
	scanf("%d",&value);
	next = head;
	while(next != NULL)
	{
		if(next->data == value)
		{
			flag = 1;
			break;
		}
		next = next->link;
		c++;
	}
	if(flag == 1)
		printf("Element present in list at %d position\n",c);
	else
		printf("Element not found\n");
}
int main()
{
	int n,ch,i;
	while(1)
	{
		printf("Program for single linked list\n");
		printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before\n");
		printf("6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before\n");
		printf("11-delete after\n12-traversal\n13-display in reverse\n14-search\n15-sort\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_position();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_before();
				break;
			case 6: insert_after();
				break;
			case 7: delete_at_begin();
				break;
			case 8: delete_at_end();
				break;
			case 9: delete_at_position();
				break;
			case 10:delete_before();
				break;
			case 11:delete_after();
				break; 
			case 12:traversal();
				break;
			case 13:reverse(head);
				break;
			case 14:search();
				break;
			case 15:sorting();
				break;
			case 16:exit(0); 
		}
	 }
}