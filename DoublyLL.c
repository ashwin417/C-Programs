#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct NODE
{
	int info;
	struct NODE *prev;
	struct NODE *next;
};
typedef struct NODE node;
node *head = NULL;
node *tail = NULL;
node *newnode(int val)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->info=val;
	p->prev=NULL;
	p->next=NULL;
	return p;
}

void InsertFirst(int item)
{
	node *p ;
	p= newnode(item);
	p->info = item;
	p->prev = NULL;
	p->next = head;
	if(head==NULL)
		head=tail=p;
	else
		head->prev = p;
		head = p;
}

void InsertBefore(int item, int item1)
{
	node *curr = head;
	node *p ;
	p= newnode(item);
	while(curr!=NULL && curr->info!=item1)
		curr = curr->next;
	if(curr == NULL)
		printf("Element not present");
	else
		
		p->info = item;
		p->next = curr;
		p->prev = curr->prev;
		if(curr == NULL)
			head=p;
		else
			curr->prev->next = p;
		curr->prev =p;
	
}

void InsertAfter(int item, int item1)
{
	node *curr = head;
	node *p;
	p=newnode(item);
	while(curr!=NULL && curr->info!=item1)
		curr = curr->next;
	if(curr == NULL)
		printf("Element not present");
	else
		
		p->info = item;
		p->prev = curr;
		p->next = curr->next;
		if(curr->next == NULL)
			tail = p;
		else
			curr->next->prev = p;
		curr->next = p;
}

void traverseright()
{
	node *curr = head;
	while(curr!=NULL)
	{
		printf("%d",curr->info);
		curr=curr->next;
		if(curr!=NULL)
		{
			printf("->");
		}
	}
		
}

void traverseleft()
{
	node *curr = tail;
	while(curr!=NULL)
	{
		printf("%d",curr->info);
		curr=curr->prev;
		if(curr!=NULL)
		{
			printf("<-");
		}
	}
	
}

void Delete(int item)
{
	node *curr = head;
	while(curr!=NULL && curr->info != item)
		curr = curr->next;
	if(curr == NULL)
		printf("No element");
	else 
	{
		
		if(curr == head)
		{
			head = curr->next;
		}
		else
		{
			curr->prev->next=curr->next;
		}
		if(curr == tail)
		{
			tail = curr->prev;
		}
		else
		{
			curr->next->prev=curr->prev;
		}
		free(curr);
		
	}
}
void main()
{
	int ch,item,item1,o;
	do
	{
	printf("\nOptions are : \n1. Insert \n2. Traverse right \n3. traverse left \n4. Delete\n5.Exit\n Enter your Option : ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		{
			printf("Enter the item to be inserted : ");
			scanf("%d",&item);
			printf("\n 1.At Beginning \t 2.Before Any Element \t 3.After any Element\nEnter your Choice : ");
			scanf("%d",&o);
			switch(o)
			{
			
			case 1: InsertFirst(item);
				break;
			case 2: printf("\n Enter the Before Element : ");
				scanf("%d",&item1);
				InsertBefore(item,item1);
				break;
			case 3:	printf("\n Enter the After Element : ");
				scanf("%d",&item1);
				InsertAfter(item,item1);
				break;
			}
		} break;
		case 2: traverseright(); break;
		case 3: traverseleft(); break;
		case 4:
			printf("Enter the element to be deleted : ");
			scanf("%d",&item);
			Delete(item);
			break;
		case 5: exit(0);break;
		default : printf("Wrong option"); break;
	}
	}
	while(1);
}
