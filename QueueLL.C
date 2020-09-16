/* IMPLEMENTING QUEUE USING LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
// Structure to define a node
typedef struct node
{
  int data;
  struct node *next;
}node;
// Structure to define queue
typedef struct queue
{
  struct node *front;
  struct node *rear;
}queue;
//Function Prototypes
queue *insert(queue *);
queue *delete(queue *);
void display (queue *);
void peek(queue *);

int main()
{
  struct queue *q=NULL;
  int ch;
  clrscr();
  while(1)
  {
    printf("\n Menu: 1.Insert 2.Delete 3.Peek 4.Display 5.Exit");
    printf("\n Enter Choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: q=insert(q);break;
      case 2: q=delete(q);break;
      case 3: peek(q);break;
      case 4: display(q);break;
      case 5: exit(0);
      default:printf("Enter a valid choice referring the menu");

    }
  }

}
// Function Definition for Displaying a queue
void display(queue *q)
{  node *ptr;
   ptr=q->front;
   if (ptr==NULL)
   {
   printf("\n Queue is Empty !!");
   }
   else
   {
     printf("Elements of the Queue are :\n");
       while (ptr!=NULL)
       {
	 printf("%d ",ptr->data);
	 ptr=ptr->next;
       }
     }
   }
// Function Definition for Inserting a element in the queue
queue *insert(queue *q)
{
  node *newnode= malloc(sizeof(node));
  printf("Enter data to be inserted:");
  scanf("%d",&newnode->data);
  if(q->front==NULL)
  {
    q->front=newnode;
    q->rear=newnode;
    q->front->next=q->rear->next=NULL;
  }
   else
   {
    q->rear->next=newnode;
    q->rear=newnode;
    q->rear->next=NULL;
   }
   return q;
  }

// Function definition to delete a element from queue
  queue *delete(queue *q)
  {
    node *ptr;
    if (q->front==NULL)
    {
     printf("QUEUE EMPTY");
    }
    else
    {
      ptr=q->front;
      q->front=q->front->next;
      printf("Element deleted =%d\n",ptr->data) ;
      free(ptr);
    }
   return q;
}
// Function definition to peep at the top of the queue
void peek (queue *q)
{
  if (q->front==NULL)
  {
   printf("Queue is Empty !!");
  }
  else
  {
    printf("\n Element at front is:%d",q->front->data);

  }
}

