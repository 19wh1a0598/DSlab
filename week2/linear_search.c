#include<stdio.h>
int linear_search(int a[50],int n,int target)
{
	int i,pos=-1;
	for(i=0;i<n;i++)
	{
		if(a[i] == target)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
int main()
{
	int n,pos,i,target,c;
	scanf("%d",&n);
	int a[n];
	for(i = 0;i < n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = linear_search(a,n,target);
	if(pos == -1)
		printf("Element not found\n");
	else
		printf("Element found at position %d location",pos+1);
}	