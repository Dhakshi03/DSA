//stack adt using char SLL

#include <cstdio>
#include <cstdlib>

class stack
{
    struct node
    {
        char data;
        struct node* next;
    };

    struct node* head= NULL;

    public:
    
    //Push
    void push(char data)
    {
        struct node* newnode = (node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=NULL;
        struct node* temp=head;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            //Traversal
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        printf("\nElement appended successfully");
    }

    //Pop
    void pop()
    {
        struct node* temp=head;
        struct node* temp2=NULL;
        if(head==NULL)
        {
            printf("\nStack empty");
            
        }
        else if(head->next==NULL)
        {
            //single node case
            printf("\nElement popped: %c",head->data);
            head=NULL;
        }
        else
        {
            //Traversal
            while(temp->next!=NULL)
            {
                temp2=temp;
                temp=temp->next;
                
            }
            printf("\nElement popped: %c",temp->data);
            temp2->next=NULL;
            printf("\nElement removed successfully");
            free(temp);
        }        
    }

    void peek()
    {
        if(head==NULL)
        {
            printf("\nStack empty");
            return;
        }
        else
        {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("\nPeek: %c",temp->data);
        }
    }

    void display()
    {
        struct node* temp=head;
        if (head==NULL)
        {
            printf("\nStack empty");
            return;
        }
        else
        {
        while(temp->next!=NULL)
        {
            printf(" %c-->",temp->data);
            temp=temp->next;
        }
        printf(" %c",temp->data);
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
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
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
                s.pop();
                break;
            }

            case 3:
            {
                s.peek();
                break;
            }

            case 4:
            {
                s.display();
                break;
            }

            case 5:
            exit(0);
        }
    }
}