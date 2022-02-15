#include<stdlib.h>
#include<stdio.h>
#define size 50
int Q[size], rear=-1,front=-1;

int isempty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if((front == rear + 1) || ((front == 0) && (rear == size - 1)))
		return 1;
	else
		return 0;
}

void Insertrear(int item)
{
	if(isfull())
		printf("Queue is Full");
	else
	{
		if(front == -1)
			front = rear = 0;
		else
			rear = (rear + 1) % size;
		Q[rear] = item;
	}
	
}

int Deletefront()
{
	int index = -1;
	if(isempty()){
		printf("Queue is empty");
	}
	else{
		index = front;
		if(front == rear)
			front = rear = -1;
		else
			front = (front +1)%size;
	}
	return index;
}

void Display()
{
	if(isempty()){
		printf("Queue is empty");
	}
	else{
	int i;
	printf("\n Queue :");
	for (i = front; i != rear; i = (i + 1) % size) {
		printf("%d ", Q[i]);
	}
	printf("%d ", Q[rear]);
	}
}

void Insertfront(int item)
{
	if(isfull())
		printf("Queue is full");
	else
		if(isempty())
			front=rear=0;
		else
			front = (front+size-1)%size;
		Q[front]= item;
}

int Deleterear()
{
	int index = -1;
	if(isempty())
		printf("Queue is empty");
	else
		index = rear;
	if(front == rear)
		front = rear = -1;
	else
		rear = (rear + size-1)%size;
	return index;
	
}



int main()
{
	int ch, fr;
	printf("Queue");
	do{
		printf("\n1.Insert 2. Delete 3.Display 4.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: {
				int item;
				printf("Item to be entered : ");
				scanf("%d",&item);
				printf("Insert it on : 1. Rear 2.Front ? ");
				scanf("%d",&fr);
				if(fr == 1)
					Insertrear(item);
				else if(fr == 2)
					Insertfront(item);
				else
					printf("wrong option");
				break;
			}
			case 2: {
				int val;
				printf("delete it from 1. front 2. rear ? ");
				scanf("%d",&fr);
				if(fr == 1)
					{
					val = Deletefront();
					}
					else if(fr == 2)
						val= Deleterear();
					else
						printf("wrong option");
				if(val != -1)
					printf("The deleted item is %d",Q[val]);
				break;
			} 
			case 3: Display(); break;
			case 4: exit(0);
		}
	} while(1);
	return 0;
}
