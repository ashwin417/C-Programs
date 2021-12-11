#include <stdio.h>
void ssort(int [],int);
void swap(int *, int *);
void selprint(int [], int);
void main()
{
	int a[30], n;
	int i;
	printf("\nEnter size of an array: ");
	scanf("%d", &n);
	printf("\nEnter elements of an array:\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	ssort(a,n);
	selprint(a, n);
	
}
void ssort(int x[],int num)
{
	int i, j, min;
	for (i=0; i<num; i++)
	{
		min = i;
		for (j=i+1; j<num; j++)
		{
			if (x[j] < x[min])
				min = j;
		}
		swap(&x[i],&x[min]);
	}
}
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void selprint(int x[], int n)
{
	int i;
	printf("\n\nAfter sorting:\n");
	for(i=0; i<n; i++)
		printf("\n%d", x[i]);
}
