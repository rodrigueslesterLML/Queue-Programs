#include <stdio.h>
#include <conio.h>
#define MAX 10 // Changing this value will change length of array
// initializing a queue empty
int queue[MAX];
int front = -1, rear = -1;

//Function Prototypes
void insert();
int delete_element();
int peek();
void display();

//Main Program
 void main()
  {
    int option, val;
   do
   {
      printf("\n\n ***** MAIN MENU *****");
      printf("\n 1. Insert an element");
      printf("\n 2. Delete an element");
      printf("\n 3. Peek");
      printf("\n 4. Display the queue");
      printf("\n 5. EXIT");
      printf("\n Enter your option : ");
      scanf("%d", &option);
switch(option)
   {
     case 1:insert();
	    break;
     case 2:val = delete_element();
	    if (val != -1) //val=-1 is underflow condition
	    printf("\n The number deleted is : %d", val);
	    break;
     case 3:val = peek();
	    if (val != -1) //val=-1 is underflow condition
	    printf("\n The first value in queue is : %d", val);
	    break;
     case 4:display();
	    break;
     }
    }while(option != 5);
  getch();
  }

 // Function Definition For insert
  void insert()
   {
	int num;
	printf("\n Enter the number to be inserted in the queue :");
	scanf("%d", &num);

     if(rear == MAX-1)//max-1 means queue is full
	printf("\n OVERFLOW");
    else
       { //if front or rear =-1 it means queue is empty
	 if(front == -1 && rear == -1)
	 {
	  front = rear = 0;// since the queue is empty we make the first space available
	  queue[rear]=num;// We make the insertion
	 }
	 else
	 {
	 rear++;// We increment rear
	 queue[rear] = num;// insert the number
	}
    }
 }


 // Function definition For delete
  int delete_element()
{
    int val;
   // front =-1 means the queue is empty
   //front>rear means we have popped more number of times than the no of elements
   if(front == -1 || front>rear)
    {
     printf("\n UNDERFLOW");
     return -1;
    }

  else
   {  // We  take the element in the val
    val = queue[front];
    front++;// We move ahead in the queue
  // this means queue is empty
  if(front > rear)
    front = rear = -1;
    return val;
   }
}

//Function Definition for Peek
  int peek()
 { // front =-1 means the queue is empty
  //front>rear means we have popped more number of times than the no of elements
   if(front==-1 || front>rear)
   {
    printf("\n QUEUE IS EMPTY");
    return -1;
   }
  else// we peek here
   {
    return queue[front];
   }
 }

 //Function Definition for Display
  void display()
 {
  int i;
  printf("\n");
  // front =-1 means the queue is empty
  //front>rear means we have popped more number of times than the no of elements
  if(front == -1 || front > rear)
  {
   printf("\n QUEUE IS EMPTY");
  }
  else
   {// We display the queue from front to end
    for(i = front;i <= rear;i++)
      printf("\t %d", queue[i]);
    }
  }
