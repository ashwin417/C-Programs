#include<stdio.h>
void Read(int[],int );
int Bsearch(int [],int,int,int);
void print(int, int);
void main()
{
	int A[100],n;
	printf("Enter the size: ");
	scanf("%d",&n);
	Read(A,n);
}
void Read(int A[],int n)
{
	int item,i,k,beg=0,end=n-1;
	printf("Enter the array : ");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("Enter the item to be searched : ");
	scanf("%d",&item);
	k=Bsearch(A,beg,end,item);
	if(k!=0)
			print(item,k);
	else
		printf("Not present");
}
int Bsearch(int A[],int beg,int end, int item)
{
	int mid = (beg + mid)/2;
	while(beg<=end)
	{
		if(A[mid]==item)
			return (mid+1);
		else if(A[mid]<item)
			return Bsearch(A,mid+1,end, item);
		else
			return Bsearch(A,beg,mid+1,item);
	return 0;
	}
}
void print(int item, int loc)
{
	printf("%d is found at position %d",item,loc);
}
