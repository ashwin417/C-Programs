#include<stdio.h>
int lsearch(int [], int, int, int);
void main()
{
	int i,a[100],n,s;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&s);
	int flag = lsearch(a,n,s,0);
	if(flag==0)
		printf("not found");
	else
		printf("found at %d",flag);
}
int lsearch(int a[], int n, int s,int i)
{
	int pos = 0;
	if(i>n)
	{
		return 0;
	}
	else if(a[i]==s)
	{
		pos = i+1;
		return pos;
	}
	else
	{
		return lsearch(a,n,s,i+1);
	}
	return pos;
}
