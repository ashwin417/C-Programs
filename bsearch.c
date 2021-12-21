#include<stdio.h>
int bsearch (int [],int, int, int);
void read(int [],int ,int );
void print(int ,int);
void main()
{
	int a[100],n,s;
	read(a,n,s);
	
}

void read(int a[],int n, int s)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&s);
	int flag = bsearch(a,0,n-1,s);
	print(flag,s);
}
int bsearch(int a[],int t, int b, int s)
{
	if(t<=b)
	{
		int m= t+(b-t)/2;
		if(a[m] == s)
			return m;
		else if(a[m]>s)
			return bsearch(a,t,m-1,s);
		else
			return bsearch(a,m+1,b,s);
	}
	else
		return -1;
}
void print(int flag, int s)
{
	if(flag==-1)
		printf("Element not present");
	else 
		printf("%d Element present at %d ",s,flag+1);
	
}
