//DLL
#include <cstdio>
#include <cstdlib>

class dll
{
    struct node
    {
        int data;
        struct node* next;
        struct node* prev;
    };

    struct node* head;
    struct node* tail;

    public:
    int count=0;

    //Constructor
    dll()
    {
        head=NULL;
        tail=NULL;
    };

    //insbeg
    void insbeg(int data)
    {
        struct node* newnode= (node*)malloc(sizeof(node));
        newnode->data=data;
        
        if (head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
            tail=newnode;
        }
        else
        {
            head->prev=newnode;
            newnode->next=head;
            newnode->prev=NULL;
            head=newnode;
        }
        count++;
    }

    //insend
    void insend(int data)
    {
        struct node* newnode= (node*)malloc(sizeof(node));
        newnode->data=data;
        
        if (head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
            tail=newnode;
        }
        else
        {
            struct node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
            tail=newnode;
        }
        count++;
    }

    //inspos
    void inspos(int data, int pos)
    {
        struct node* newnode= (node*)malloc(sizeof(node));
        newnode->data=data;

        if(pos<1 || pos>count+1)
        {
            printf("\nOut of bounds!");
            return;
        }
        else if (head==NULL || pos==1)
        {
            insbeg(data);
        }
        else if(pos<=count)
        {
            struct node* temp=head;
            while(--pos>1)
            {
                temp=temp->next;
            }
            newnode->prev=temp;
            newnode->next=temp->next;
            if (temp->next!=NULL)
            {
                temp->next->prev=newnode;
            }
            temp->next=newnode;
            
        }
        else if(pos==count+1)
        {
            insend(data);
        }
        count++;
    }

    //delbeg
    void delbeg()
    {
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        else if(count==1)
        {
            head==NULL;
        }
        else
        {
            struct node* temp=head;
            head=head->next;
            head->prev=NULL;
            free(temp);
        }
        count--;
    }

    //delend
    void delend()
    {
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        else if(count==1)
        {
            head==NULL;
        }
        else
        {
            struct node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            free(temp);
        }
        count--;
    }

    //delpos
    void delpos(int pos)
    {
        if(pos<1 || pos>count+1)
        {
            printf("\nOut of bounds!");
            return;
        }
        else if (head==NULL || pos==1)
        {
            delbeg();
            return;
        }
        else if(pos<=count)
        {
            struct node* temp=head;
            
            while(--pos>1)
            {
                temp=temp->next;
            }
            struct node* todel=temp->next;
            temp->next=todel->next;
            if (todel->next!=NULL)
            {
                todel->next->prev=temp;
            }
            free(todel);   
        }
        else if(pos==count)
        {
            delend();
        }
        count--;
    }

    //search
    void search(int data)
    {
        int place=1;
        struct node* temp=head;
        while(place<=count)
        {
            if (temp->data==data)
            {
                printf("\nNumber found at %d position.",place);
                return;
            }
            temp=temp->next;
            place++;
        }
        printf("\nNumber not found");
    }

    //display
    void displayforward()
    {
        if(head==NULL)
        {
            printf("\nList is empty");
        }
        else
        {
            struct node* temp=head;
            while(temp->next!=NULL)
            {
                printf("%d-->",temp->data);
                temp=temp->next;
            }
            printf("%d",temp->data);
        }
    }

    //display reverse
    void displayreverse()
    {
        if(head==NULL)
        {
            printf("\nList is empty");
        }
        else
        {
            struct node* temp=tail;
            while(temp->prev!=NULL)
            {
                printf("%d<--",temp->data);
                temp=temp->prev;
            }
            printf("%d",temp->data);
        }
    }
};

int main()
{
    dll dll;

    int choice, data, pos;

    while(1)
    {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position");
        printf("\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position");
        printf("\n7.Search\n8.Display Foward\n9.Display in Reverse\n10.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                //Ins at beg
                printf("\nEnter number: ");
                scanf("%d",&data);
                dll.insbeg(data);
            break;
            }

            case 2:
            {
                //Ins at end
                printf("\nEnter number: ");
                scanf("%d",&data);
                dll.insend(data);
            break;
            }

            case 3:
            {
                //Ins at position
                printf("\nEnter number: ");
                scanf("%d",&data);
                printf("\nEnter position: ");
                scanf("%d",&pos);
                dll.inspos(data,pos);
                break;
            }

            case 4:
            {
                //delbeg
                dll.delbeg();
            break;
            }

            case 5:
            {
                //Delend
                dll.delend();
                break;
            }

            case 6:
            {
                //Delpo
                printf("\nEnter position: ");
                scanf("%d",&pos);
                dll.delpos(pos);
            break;
            }

            case 7:
            {
                //Search
                printf("\nEnter number you want to search for: ");
                scanf("%d",&data);
                dll.search(data);
            break;
            }

            case 8:
            {
                //Display forward
                dll.displayforward();
            break;
            }

            case 9:
            {
                //Display reverse
                dll.displayreverse();
            break;
            }
            
            case 10:
            {
                //Exit
                exit(0);
            break;
            }

        }
           
    }

    return 0;
}