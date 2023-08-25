#include <stdio.h>
#define maxsize 5
int a[maxsize];
int front =0;
int rear = 0;

//inserting an element function
void insert(int ele)
{
    if ((rear +1)% maxsize == front)
    {
      printf("the queue is full, delete some elements to enter more elements ");
    }
    else
    {
        rear = (rear +1) % maxsize ;
        a[rear]=ele;
    }
}

//deleting an element function

int Delete()
{
    if (front == rear)
    {
        printf("the queue is empty , enter some elements to delete ");
        return(-9999);
    }
    else
    {
        front = (front + 1)%maxsize;
        return(a[front]);
    }

}

//displaying function
int display()
{
    int i=front;
   do
   {
       i=(i+1)%maxsize;
       printf("%d" , a[i]);
   }while(i!=rear);

}

int main()
{
    insert(5);
    insert(4);
    insert(3);
    insert(4);
    Delete();
    Delete();
    Delete();
    display();
}
