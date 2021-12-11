#include<stdio.h>
void msort(int [], int, int, int);
void main()
{
	
}

void msort(int a[], int f, int s, int t)
{
	int t[100], i=f,j=s,k=0;
	while(i<s && j<=t)
	{
		if(a[i]<a[j])	
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i<s)
		temp[k++] = a[i++];
	while(j<=t)
		temp[k++] = a[j++];
	for(i=f,j=0;j<k;)
		a[i++]=temp[j++];
}
