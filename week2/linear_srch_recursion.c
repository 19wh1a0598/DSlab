#include<stdio.h>
int linear_search(int a[50],int n,int target)
{
	static int i,pos;
	if(a[i]==target)
	{
		pos=i;
		return i;
	}
	else if(i < n)
	{
		i++;
		linear_search(a,n,target);
	}
	else
		return -1;
}
int main()
{
	int n,pos,i,target;
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