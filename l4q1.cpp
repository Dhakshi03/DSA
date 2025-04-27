//SLL

#include <cstdio>
#include <cstdlib>
#include <iostream>

class List
{
    private:
    struct node
    {
        int data;
        struct node* next;
    };
    struct node* head;

    public:
    List()
    {
        head=NULL;
    };

    //Accessing head    
    struct node* gethead()
    {
        return head;
    }

    //Insert Beginning
    void insbeg(int num)
    {
        struct node* newnode=(node*)malloc(sizeof(node));
        newnode->data=num;

        if (head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    //Insert at end
    void insend(int num)
    {
        struct node* newnode=(node*)malloc(sizeof(node));
        newnode->data=num;

        if (head==NULL)
        {
            insbeg(num);
        }
        else
        {
            //traversal
            struct node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=NULL;
        }
    }

    //Insert position
    void inspos(int num, int pos)
    {
        struct node* newnode=(node*)malloc(sizeof(node));
        newnode->data=num;

        if (head==NULL or pos==1)
        {
            insbeg(num);
        }
        else if(pos<0)
        {
            printf("\nInvalid position");
        }
        else
        {
            //traversal till position-1
            struct node* temp=head;
            while(pos>2)
            {
                temp=temp->next;
                pos--;
            }

            if (pos>2)
            {
                printf("\nPosition is out of range");
            }

            newnode->next=temp->next;
            temp->next=newnode;  
        }
    }

    //Delete beginning
    void delbeg()
    {
        if(head==NULL)
        {
            printf("\nEmpty List");
        }
        else
        {
            struct node* temp=head;
            head=head->next;
            temp->next=NULL;
            temp=NULL;
        }
    }

    //Delete end
    void delend()
    {
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        else if (head->next==NULL)
        {
            free(head);
            head=NULL;
            return;
        }
        else
        {
            struct node* temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            //free(temp->next);
            temp->next=NULL;
        }
    }

    //Delete position
    void delpos(int pos)
    {
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        else if(pos==1)
        {
            delbeg();
            return;
        }
        else
        {
            struct node* temp=head;

            //traversal till position-1
            for(int i=0; i<pos-2; i++)
            {
                if(temp->next==NULL)
                {
                    printf("\nPosition out of bounds");
                    return;
                }
                temp=temp->next;
            }

            if(temp == NULL || temp->next == NULL)
            {
                printf("\nPosition out of range");
                return;
            }

            temp->next=temp->next->next;
        }
    }

    //Search
    void search(int num)
    {
        struct node* temp= head;
        while(temp!=NULL)
        {
            if (temp->data==num)
            {
                printf("\nFound!");
                return;
            }
            temp=temp->next;
        }
        printf("\nNot Found");
    }

    //Display
    void display()
    {
        struct node* temp= head;
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        else{
            while(temp->next!=NULL)
            {
            printf("%d-->",temp->data);
            temp=temp->next;
            }
            printf("%d",temp->data);
        } 
    }

    //Display in reverse - Recursion
    void displayrev(node*head)
    {
        struct node* temp= head;
        if(head==NULL)
        {
            printf("\nEmpty list");
            return;
        }
        if(temp->next==NULL)
        {
            printf("%d",temp->data);
            return;
        }

        displayrev(temp->next);
        printf("<--%d",temp->data);
    }

    //Reverse link
    void revlink(node* head)
    {
        struct node* temp= head;

        if(temp==NULL)
        {
            return;          
        }
        if(temp->next==NULL)
        {
            printf("%d",temp->data);
            return;
        }

        displayrev(temp->next);
        printf("<--%d",temp->data);
    }
    
};

int main()
{
    int choice, num, pos;
    List sll;

    while(1)
    {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position");
        printf("\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position");
        printf("\n7.Search\n8.Display Foward\n9.Display in Reverse\n10.Reverse Link\n11.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                //Insert beginning
                printf("\nEnter number: ");
                scanf("%d",&num);
                sll.insbeg(num);
                break;
            }

            case 2:
            {
                //Insert end
                printf("\nEnter number: ");
                scanf("%d",&num);
                sll.insend(num);
                break;
            }

            case 3:
            {
                //Insert position
                printf("\nEnter number: ");
                scanf("%d",&num);
                printf("\nEnter position: ");
                scanf("%d",&pos);
                sll.inspos(num, pos);
                break;
            }

            case 4:
            {
                //Delete beginning
                sll.delbeg();
                break;
            }

            case 5:
            {
                //Delete end
                sll.delend();
                break;
            }

            case 6:
            {
                //Delete position
                printf("\nEnter position: ");
                scanf("%d",&pos);
                sll.delpos(pos);
                break;
            }

            case 7:
            {
                //Search
                printf("\nEnter number to search for: ");
                scanf("%d",&num);
                sll.search(num);
                break;
            }

            case 8:
            {
                //Display
                sll.display();
                break;
            }

            case 9:
            {
                //Display in reverse
                sll.displayrev(sll.gethead());
                break;
            }

            case 11:
            {
                //Exit
                exit(0);
            }
        }
    }
}