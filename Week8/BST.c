#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left,*right;
};
struct BST* root=NULL,*temp,*cur;
void create()
{
	char c[10];
	temp = root;
	cur = (struct BST*)malloc(sizeof(struct BST));
	printf("\n Enter Data:\n");
	scanf("%d",&(cur->data));
	cur->left = NULL;
	cur->right = NULL;
	if(temp == NULL)
		root = cur;
	else
	{
		while(temp != NULL)
		{
			if((cur->data) < (temp->data))
			{
				if(temp->left == NULL)
				{
					temp->left = cur;
					return;
				}
				else
					temp = temp->left;
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = cur;
					return;
				}
				else
					temp = temp->right;
			 }
		  }
	}
}
void postorder(struct BST *temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("\t%d",temp->data);
	}
}
void inorder(struct BST *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("\t%d",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct BST *temp)
{
	if(temp != NULL)
	{
		printf("\t%d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
int main()
{
	int ch;
	printf("\n menu options\n");
	printf("1.Create\n2.Postorder\n3.Preorder\n4.Inorder\n5.exit\n");
	while(1)
	{
		printf("\n Enter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
				break;
			case 2:printf("Postorder Traversal\n");
				postorder(root);
				break;
			case 3:printf("Preorder Traversal\n");
				preorder(root);
				break;
			case 4:printf("Inorder Traversal\n");
				inorder(root);
				break;
			case 5:exit(0);
			default: printf("Invalid choice\n");
		}
	}
}