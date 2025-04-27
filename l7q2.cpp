//Circular queue using array of size 5

#include <cstdio>
#include <cstdlib>
#include <iostream>

class queue
{
    private:
    int arr[5];
    int front, rear;

    public:
    queue()
    {
        front = rear= -1;
    }

    //enqueue
    void enq(int data)
    {
        if ((rear+1)%5==front)
        {
            printf("\nQueue full!");
            return;
        }
        if (front==-1)
        {
            arr[0]=data;
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%5; //first update rear to ensure that the data doesnt get added in out of bounds region
            arr[rear]=data;
        }
    }

    //dequeue
    void deq()
    {
        if (front==-1)
        {
            printf("\nQueue Empty");
            return;
        }
        else
        {
            if (front==rear) //queue is empty only if front=rear and not front=0
            {
                front=rear=-1;
            }
            else
            {
                front=(front+1)%5;
            }
        }
    }

    //peek
    void peek()
    {
        if (front==-1)
        {
            printf("\nEmpty queue");
            return;
        }
        else
        {
            printf("%d",arr[front]);
        }
    }
};

int main()
{
    int choice, data;

    queue q;

    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            //enqueue
            printf("\nEnter data: ");
            scanf("%d",&data);
            q.enq(data);
            break;

            case 2:
            q.deq();
            break;

            case 3:
            q.peek();
            break;

            case 4:
            exit(0);
        }
    }
}