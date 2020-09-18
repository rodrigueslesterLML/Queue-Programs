#include <stdio.h>

#define MAX 10
//initializing a queue(here circular)
int queue[MAX];
//front=rear=-1 means queue is empty
int front=-1, rear=-1;

//Function Prototypes:
void insert();
int delete_element();
int peek(void);
void display();

//Main program:
void main()

{
  int option, val;
  clrscr();
while(1)
  {
    printf("\n ***** MAIN MENU *****");
    printf("\n 1. Insert an element");
    printf("\n 2. Delete an element");
    printf("\n 3. Peek");
    printf("\n 4. Display the queue");
    printf("\n 5. EXIT");
    printf("\n Enter your option : ");
   scanf("%d", &option);
 switch(option)
{case 1:insert();
	break;
 case 2:val = delete_element();
       if(val!=-1)
	 printf("\n The number deleted is : %d", val);
       break;
case 3:val = peek();
       if(val!=-1)
	printf("\n The first value in queue is : %d", val);
	 break;
  case 4:display();
       break;
 case 5:exit(0);

 default:printf("Wrong choice Entered");
}
}


}
//Function Definition for insert:
void insert()
{
  int num;
  printf("\n Enter the number to be inserted in the queue : ");
  scanf("%d", &num);
 //Condition checked is if the queue is full
if(front==0 && rear==MAX-1)
   {
    printf("\n OVERFLOW");
}
//Condition checked is if queue is empty
else if(front==-1 && rear==-1)
{
 front=rear=0;
 queue[rear]=num;
}
// Condition checked if the front of the queue has space
else if(rear==MAX-1 && front!=0)
{
  rear=0;//therefore we bring rear in the front since the front has space
  queue[rear]=num;
}
//Else Normal Insertion
else
{
  rear++;
  queue[rear]=num;
}
}

int delete_element()
{
 int val;
 //Condition Checked is if queue is empty
 if(front==-1 && rear==-1)
 {
   printf("\n UNDERFLOW");
   return -1;
}
//if not empty deletions occur from front
val = queue[front];
//front==rear means only element present
   if(front==rear)
    { front=rear=-1;}
  else
   { //if last element encountered then move to the first element
    if(front==MAX-1)
     {
      front=0;
     }
    //Else normal incrementation of front
    else
    {
     front++;
      } }
return val;// the value deleted
}

// Function Definition For peek

 int peek()
  { //Condition checked : if queue is empty
   if(front==-1 && rear==-1)
  {
    printf("\n QUEUE IS EMPTY");
    return -1;
  }
 else//else we peek
  {
    return queue[front];
  }
 }
  void display()
{
	int i;
	printf("\n");
 // front =rear=-1 circular queue is empty
 if (front ==-1 && rear==-1)
  {

    printf ("\n QUEUE IS EMPTY");

  }
else
  {      //front<rear means elements occupy spaces from front to rear
	  if(front<rear)
	     {
		for(i=front;i<=rear;i++)
	   {
	    printf("\t %d", queue[i]);
	   }
	       }

	  else //front>rear  means front range is from front to max and rear range is from 0 to rear
	    {
	       for(i=front;i<MAX;i++)
	      {
		  printf("\t %d", queue[i]);
		}
		    for(i=0;i<=rear;i++)
	       {
		  printf("\t %d", queue[i]);
	       }
	    }
     }
}


