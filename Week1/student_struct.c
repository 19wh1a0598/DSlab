#include<stdio.h>
struct student
{
	char roll[15];
	char name[30];
	int m[3];
};
int main()
{
	char grade;
	struct student s[3];
	int n,i,j;
	scanf("%d",&n);
	float avg,sum = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%s",s[i].roll);
		sum = 0;
		scanf("%s",s[i].name);
		for(j = 0;j < 3;j++)
		{
			scanf("%d",&s[i].m[j]);
			sum += s[i].m[j];
		}
		avg = sum/3.0;
		if (avg >= 80.0)
			grade = 'A';
		else if (avg <= 40.0 && avg < 80.0)
			grade = 'B';
		else
			grade = 'C';
		printf("roll = %s\t name = %s\t grade = %c\n",s[i].roll,s[i].name,grade);
	}
}
		