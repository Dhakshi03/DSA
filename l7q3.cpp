#include <cstdio>
#include <cstdlib>

class queuel
{
    struct node
    {
        int data;
        struct node *next;
    } *front, *rear;

public:
    queuel()
    {
        front = rear = NULL;
    }

    int enqueue(int num)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;

        if (front == NULL)
        {
            front = rear = newnode;
            return 1;
        }
        rear->next = newnode;
        rear = newnode;
        return 1;
    }

    int dequeue()
    {
        if (front == NULL)
        {
            printf("Queue is empty\n");
            return 0;
        }

        struct node *temp = front;
        front = front->next;
        free(temp);
        return 1;
    }

    int peek()
    {
        if (front == NULL)
        {
            printf("Queue is empty\n");
            return -1;
        }
        return front->data;
    }

    void display()
    {
        if (front == NULL)
        {
            printf("Queue is empty\n");
            return;
        }

        struct node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main()
{
    queuel ql;
    int choice, num, res;

    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                if (ql.enqueue(num))
                {
                    printf("Entered successfully\n");
                    ql.display();
                }
                break;

            case 2:
                if (ql.dequeue())
                {
                    printf("Deleted successfully\n");
                    ql.display();
                }
                break;

            case 3:
                res = ql.peek();
                if (res != -1)
                    printf("The element is: %d\n", res);
                break;

            case 4:
                printf("Exited\n");
                exit(0);

            default:
                printf("Enter valid choice\n");
        }
    }
    return 0;
}
