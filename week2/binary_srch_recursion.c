#include<stdio.h>
int binary_search(int first,int last,int a[50],int target)
{
	int mid,pos = -1;
	if(first <= last)
	{
		mid = (first+last)/2;
		if(a[mid] == target)
			return mid;
		else if(target < a[mid])
			binary_search(first,mid-1,a,target);
		else
			binary_search(mid+1,last,a,target);
	}
	else
		return -1;
}
int main()
{
	int n,i,pos,target;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = binary_search(0,n-1,a,target);
	if(pos == -1)
		printf("Element not found\n");
	else
		printf("Element found at position at %d position",pos+1);
}
		
