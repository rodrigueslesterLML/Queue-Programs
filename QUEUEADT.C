#include<stdlib.h>
#include<stdio.h>
#define size 50
//initialiazing queue of size 50
int queue[size];
//this means queue is empty
int front=-1;
int rear=-1;

//Function Definition for insert:
void insert(int val)
{ if(rear==-1)//Queue is emoty
  { front=rear=0;//therefore 1st element is inserted
    queue[rear]=val;
  }
  else //If queue is not empty its either full or elements are present
  { if(rear==size-1)//if queue is full
   printf("The Queue full!! Item cant be inserted!");
   else//else normal insertion
     { rear=rear+1;
      queue[rear]=val;
      }
   }
}

//Function Definition for delete
void delete()
{ if(front==-1)//queue is empty
printf("Queue is empty!!");
else//If queue is not empty we remove the item
{
  printf("Item removed is %d",queue[front]);
  if(front==rear)//if after removing front ==rear it means only 1 element present
     { front=-1;
       rear=-1; /*Reseting for an empty queue*/
      }
  else
       front=front+1;//else we increment front to implement the deletion
  }
}

//Function Definition for peep
void peep()
{
int val;
if(front==-1) //IF queue is empty
printf("Queue Empty!!\n");
else
{
printf("Element at the front=%d",queue[front]);//else element at front is peeped at
}
}
//Function Definition for display
void display()
{ int i;
if(front==-1)//queue empty
printf("Queue Empty!!\n");
else
{ printf("\nQueue elements:\n");
for(i=front;i<=rear;i++)//displaying from front to rear
printf(" %d",queue[i]);
}
}

void main() //Main program to implement a using array
{
int choice; int val;
while(1)
{
printf("\n 1. Insert 2. Delete3. Peep4. Display 5. Exit\n Enter your choice:");
scanf("%d",&choice);
  switch(choice)
   { case 1: printf("Enter value");
	  scanf("%d",&val);
	  insert(val);break;
     case 2: delete(); break;
     case 3: peep(); break;
     case 4: display(); break;
     case 5: exit(0);
    default: printf("Enter valid choice!!\n");exit(0);
  }
}

}