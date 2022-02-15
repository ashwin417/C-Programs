//deletion from end is only working other ain't!!!

#include<stdio.h>
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
	node *p = newnode(item);
	p->info = item;
	p->prev = NULL;
	p->next = head;
	if(head==NULL)
		head=tail=p;
	else
		head->prev = p;
		head = p;
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
	while(curr->info != item)
		curr = curr->next;
	if(curr->next = NULL)
		printf("No element");
	else 
	{
		if(curr == tail)
		{
			tail = tail->prev;
			if(tail!=NULL)
				tail->next = NULL;
			free(curr);
		}
		else if(curr == head)
		{
			head = head->next;
			if(head!=NULL)
				head->prev = NULL;
			free(curr);
		}
		else
		{
			node *temp = curr -> next;  
			curr -> next = temp -> next;  
			temp -> next -> prev = curr; 
			free(temp);
		}
		
	}
}
void main()
{
	int ch,item,item1;
	do
	{
	scanf("%d",&ch);
	switch(ch){
		case 1:
			scanf("%d",&item);
			InsertFirst(item);
			break;
		case 2:
			scanf("%d",&item);
			scanf("%d",&item1);
			InsertAfter(item,item1);
			break;
		case 3: traverseright(); break;
		case 4: traverseleft(); break;
		case 5:
			scanf("%d",&item);
			Delete(item);
			break;
	}
	}
	while(1);
}
