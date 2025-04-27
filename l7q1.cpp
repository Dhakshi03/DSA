#include <iostream>
#include <cstdio>
#include <cstdlib>

class queue
{
    private:
    int arr[5];
    int front, rear;

    public:
    //Constructor
    queue()
    {
        front=-1;
        rear=-1;
    }

    //enqueue
    void enqueue(int num)
    {
        if (rear==4)
        {
            printf("\nQueue is full!");
        }
        else
        {
            if(front==-1)
            {
                front=0;
            }
            arr[rear+1]=num;
            rear+=1;
        }
    }

    //dequeue
    void dequeue()
    {
        if (front==-1 || front>rear)
        {
            printf("\nEmpty queue");
            front=rear=-1;
        }
        else
        {
            for(int i=0;i<rear+1;i++)
            {
                arr[i]=arr[i+1];
            }
            rear-=1;
        }
    }

    //peek
    void peek()
    {
        if (front==-1 || front>rear)
        {
            printf("\nEmpty queue");
            front=rear=-1;
        }
        else
        {
            printf("%d",arr[rear]);
        }
    }

    //display
    void display()
    {
        if(front==-1 || front>rear)
        {
            printf("\nEmpty queue");
        }
        else
        {
        for(int i=0;i<rear+1;i++)
        {
            printf("%d ",arr[i]);
        }
        }
    }
};

int main()
{
    queue q;
    int choice, num;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
            printf("\nEnter number: ");
            scanf("%d",&num);
            q.enqueue(num);
            break;

            case 2:
            q.dequeue();
            break;

            case 3:
            q.peek();
            break;

            case 4:
            q.display();
            break;

            case 5:
            exit(0);
        }
    }
}
