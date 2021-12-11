
	#include<stdio.h>
	
	int lsearch(int [], int, int);
	
	void main()
	{
		int a[50], s, i, n, pos;
		
		printf("Enter the number of elements in array\n");
		scanf("%d",&n);
		
		printf("Enter %d numbers\n", n);
		
		for ( i = 0 ; i < n ; i++ )
			scanf("%d",&a[i]);
		
		printf("Enter the number to search\n");
		scanf("%d",&s);
		
		pos = lsearch(a, n, s);
		
		if ( pos == -1 )
			printf("%d is not present in array.\n", s);
		else
			printf("%d is present at location %d.\n", s, pos+1);
		
		
	} 
	
	int lsearch(int p[], int n, int f)
	{
		int c;
		
		for ( c = 0 ; c < n ; c++ )
		{
			if ( p[c] == f )
				return c;
		}
		
		return -1;
	}
