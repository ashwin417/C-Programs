#include <stdio.h>
void bsort(int [],int);
void swap(int *, int *);
void bprint(int [], int);
void main()
{
	int a[30], n;
	int i;
	printf("\nEnter size of an array: ");
	scanf("%d", &n);
	printf("\nEnter elements of an array:\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	bsort(a,n);
	bprint(a, n);
	
}
void bsort(int x[],int num)
{
	int i, j;
	for (i=0; i<num-1; i++)
	{
		
		for (j=0; j<num-i-1; j++)
		{
			if (x[j] > x[j+1])
				swap(&x[j],&x[j+1]);
		}
		
	}
}
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void bprint(int x[], int n)
{
	int i;
	printf("\n\nAfter sorting:\n");
	for(i=0; i<n; i++)
		printf("\n%d", x[i]);
}
