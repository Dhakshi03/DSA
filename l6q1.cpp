//stack adt using char arr of size 5

#include <cstdio>
#include <cstdlib>

class stack
{
    char arr[5];
    int top;

    public:
    //Constructor
    stack()
    {
        top=-1;
    }

    //Push
    void push(char data)
    {
        if (top==4)
        {
            printf("\nStack full!\nElement not appended");
        }
        else
        {
            arr[++top]=data;
            printf("\nElement appended successfully!");
        }
    }

    //Pop
    char pop()
    {
        if (top==-1)
        {
            printf("\nStack empty!");
            return '-';
        }
        else
        {
            printf("\nElement removed successfully");
            return arr[top--];
        }
    }

    //Peek
    char peek()
    {
        if (top==-1)
        {
            printf("\nStack empty!");
            return '-';
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{
    stack s;
    int choice;
    char data;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter character: ");
                scanf(" %c",&data);
                s.push(data);
                break;
            }

            case 2:
            {
                printf("\nElement removed: %c",s.pop());
                break;
            }

            case 3:
            {
                printf("\nPeek element: %c",s.peek());
                break;
            }

            case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}