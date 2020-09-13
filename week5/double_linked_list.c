#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head = NULL,*tail = NULL,*cur,*t1,*t2;
void create()
{
	int i,n;
	printf("Enter the no.of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("Enter current data part\n");
		scanf("%d",&(cur->data));
		cur->prev = NULL;
		cur->next = NULL;
		if(head == NULL)
			head=tail=cur;
		else
		{
			tail->next = cur;
			cur->prev = tail;
			tail = cur;
		}
	}
}		
void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current data part\n");
	scanf("%d",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head = cur;
}
void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current data part\n");
	scanf("%d",&(cur->data));
	cur->next = NULL;
	cur->prev = tail;
	tail->next = cur;
	tail = cur;
}
void insert_at_position()
{
	int c,pos;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current data part\n");
	scanf("%d",&(cur->data));
	printf("Enter position to insert\n");
	scanf("%d",&pos);
	c=1;
	t1 = head;
	while(c < pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next = cur;
	cur->prev = t2;
	cur->next = t1;
	t1->prev = cur;
}
void insert_before()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current data part\n");
	scanf("%d",&(cur->data));
	printf("Enter the data before which we need to insert\n");
	scanf("%d",&value);
	t1 = head;
	while(t1->data != value && t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
	}
	t2->next = cur;
	cur->prev = t2;
	t1->prev = cur;
	cur->next = t1;
} 
void insert_after()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter current data part\n");
	scanf("%d",&(cur->data));
	printf("Enter the data after which we need to insert\n");
	scanf("%d",&value);
	t1 = head;
	while(t1->data != value && t1 != NULL)
	{
		t1 = t1->next;
	}
	cur->next = t1->next;
	t1->next->prev = cur;
	t1->next = cur;
	cur->prev = t1;
}
void delete_at_begin()
{
	cur = head;
	head = head->next;
	head->prev = NULL;
	cur->next = NULL;
	printf("Deleted data is %d\n",cur->data);
	free(cur);
}
void delete_at_end()
{
	cur = tail;
	tail = tail->prev;
	tail->next = NULL;
	cur->prev = NULL;
	printf("Deleted data is %d\n",cur->data);
	free(cur);
}
void delete_at_position()
{
	int pos,c=1;
	printf("Enter the position of data to be deleted\n");
	scanf("%d",&pos);
	t1 = head;
	while(c < pos && t1 != NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("Deleted data is %d\n",t1->data);
	free(t1);
	
}
void delete_before()
{
	int value;
	printf("Enter the value before which data to be deleted\n");
	scanf("%d",&value);
	t1 = head;
	while(t1->next->data != value && t1->next != NULL)
	{
		t2 = t1;
		t1 = t1->next;
	}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("Deleted data is %d\n",t1->data);
	t1->prev = t1->next = NULL;
	free(t1);
}
void delete_after()
{
	int value;
	printf("Enter the value after which data to be deleted\n");
	scanf("%d",&value);
	t1 = head;
	while(t1->data != value && t1 != NULL)
	{
		t1 = t1->next;
	}
	t2 = t1->next;
	t1->next = t2->next;
	t2->next->prev = t1;
	printf("Deleted data is %d\n",t2->data);
	t2->prev = t2->next = NULL;
	free(t2);
}
void display()
{
	if(head == NULL)
		printf("DLL is empty\n");
	else
	{
		cur = head;
		while(cur != NULL)
		{
			printf("%d<->",cur->data);
			cur = cur->next;
		}
	}
} 
void reverse()
{
	if(head == NULL)
		printf("DLL is empty\n");
	else
	{
		cur = tail;
		while(cur != NULL)
		{
			printf("%d<->",cur->data);
			cur = cur->prev;
		}
	}
} 
void sort()
{
	struct node *p1,*p2,*last=NULL;
	int i,c,t;
	c=0;
	p1 = head;
	while(p1->next != NULL)
	{
		c++;
		p1 = p1->next;
	}
	for(i=0;i<c;i++)
	{
		p2 = head;
		while(p2->next != NULL)
		{
			if(p2->data > p2->next->data)
			{
				t = p2->data;	
				p2->data = p2->next->data;
				p2->next->data = t;
			}
			p2 = p2->next;
		}
	}
	
}
void search()
{
	int value,c,flag=0;
	printf("Enter the value to search\n");
	scanf("%d",&value);
	c = 1;
	t1 = head;
	while(t1 != NULL)
	{
		if(t1->data == value)
		{
			flag = 1;
			break;
		}
		t1 = t1->next;
		c++;
	 }
	if(flag == 1)
		printf("Element present at %d position\n",c);
	else
		printf("Element not found\n");
}
int main()
{
	int n,ch,i;
	while(1)
	{
		printf("Program for double linked list\n");
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
			case 12:display();
				break;
			case 13:reverse();
				break;
			case 14:search();
				break;
			case 15:sort();
				break;
			case 16:exit(0); 
		}
	 }
}
	
	
