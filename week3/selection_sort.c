#include<stdio.h>
void selection_sort(int a[100],int n)
{
	int i,j,t,min;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)

		{
			if(a[j] < a[min])
				min = j;
		}
		t = a[i];
		a[i] = a[min];
		a[min] = t;
	 }
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selection_sort(a,n);
	printf("Elements after sorting\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
