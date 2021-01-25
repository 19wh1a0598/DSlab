#include<stdio.h>
#include<stdlib.h>
int source,V,E,time,visited[20],G[20][20];
void DFS(int i)
{
	int j;
	visited[i] = 1;
	printf("%d->",i+1);
	for(j=0;j<V;j++)
	{
		if(G[i][j] == 1 && visited[j] == 0)
			DFS(j);
	}
}
int main()
{
	int i,j,v1,v2;
	printf("\t\t\tGraphs\n");
	printf("Enter the no.of edges: \n");
	scanf("%d",&E);
	printf("Enter the no.of vertices: \n");
	scanf("%d",&V);
	printf("\n Enter graph data in matrix form:\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	printf("Enter thr source: ");
	scanf("%d",&source);
		DFS(source-1);
	return 0;
}

