#include<stdio.h>
void smallpos(int [],int );
int main() {
	int x[30], i, num;
	printf("\nEnter no of elements :");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
		scanf("%d", &x[i]);
	smallpos(x,num);
}	
void smallpos(int a[],int n)
{	
	int i,smallest,pos;
	smallest = a[0];
	for (i = 0; i < n; i++) 
	{
		if (a[i] < smallest) 
		{
			smallest = a[i];
			pos = i;
		}
	}
	printf("\nSmallest Element : %d at %d position", smallest,pos);
	
	
}
