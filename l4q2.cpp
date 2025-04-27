//SLL merging lists

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "l4q2.h"

/*
class list
{
    private:
    struct node
    {
        int data;
        struct node* next;
    };

    struct node* head;

    public:
    list()
    {
        head=NULL;
    };

    void sethead(struct node* newhead) // Allow setting head
    {
        head = newhead;
    };

    struct node* gethead()
    {
        return head;
    }

    //Insert ascending
    void insasc(int num)
    {
        struct node* newnode=(node*)malloc(sizeof(node));
        newnode->data=num;

        //Empty list or newnode has the smallest element
        if(head==NULL || head->data>newnode->data)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            struct node* temp=head;
            
            if(temp->next!=NULL && newnode->data>temp->next->data)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

    //Merging two lists
    struct node* merge(struct node* head1, struct node* head2)
    {
        struct node*temp1=head1;
        struct node*temp2=head2;
        struct node* head3=NULL;
        struct node*temp3=NULL;

        while(temp1!=NULL && temp2!=NULL)
        {
        struct node* newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        //Storing data in newnode
        if(temp1->data>temp2->data)
        {
            newnode->data=temp2->data;
            temp2=temp2->next;
        }
        else
        {
            newnode->data=temp1->data;
            temp1=temp1->next;
        }
        
        //Empty l3 => initialize it
        if(head3==NULL)
        {
            head3=newnode;
            temp3=head3;
        }
        //If l3 is not empty => append newnode and update temp3
        else
        {
            temp3->next=newnode;
            temp3=temp3->next;
        }
        }

        //Append remaining elements from list1, if any
        while(temp1!=NULL)
        {
            struct node* newnode=(node*)malloc(sizeof(node));
            newnode->next=NULL;
            newnode->data=temp1->data;
            
            //Empty l3 => initialize it
            if(head3==NULL)
            {
            head3=newnode;
            temp3=head3;
            }
            //If l3 is not empty => append newnode and update temp3
            else
            {
            temp3->next=newnode;
            temp3=temp3->next;
            }

            temp1=temp1->next;
        }

        //Append remaining elements from list2, if any
        while(temp2!=NULL)
        {
            struct node* newnode=(node*)malloc(sizeof(node));
            newnode->next=NULL;
            newnode->data=temp2->data;
            
            //Empty l3 => initialize it
            if(head3==NULL)
            {
            head3=newnode;
            temp3=head3;
            }
            //If l3 is not empty => append newnode and update temp3
            else
            {
            temp3->next=newnode;
            temp3=temp3->next;
            }

            temp2=temp2->next;
        }
        return head3;
        }

    //Display
    void display()
    {
        struct node* temp=head;

        if(head==NULL)
        {
            printf("\nEmpty List");
            return;
        }

        while(temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }

};
*/

int main()
{
    list list1, list2, list3;
    int choice, num;

    while(1)
    {
        printf("\n\n1.Insert into list1\n2.Insert into list2\n3.Merge l1 and l2 into list3");
        printf("\n4.Display list1\n5.Display list2\n6.Display list3\n7.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch ((choice))
        {
        case 1:
        {
            //Insert into list1
            printf("\nEnter number: ");
            scanf("%d",&num);
            list1.insasc(num);
            break;
        }

        case 2:
        {
            //Insert into list2
            printf("\nEnter number: ");
            scanf("%d",&num);
            list2.insasc(num);
            break;
        }

        case 3:
        {
            //Merge list1 and list2
            list3 = list(); // Reset list3 before merging
            list3 = list(); // Reset list3
            list3.sethead(list3.merge(list1.gethead(), list2.gethead())); // Update head manually
            printf("\nLists merged successfully!");
            break;
        }

        case 4:
        {
            //Display list1
            list1.display();
            break;
        }

        case 5:
        {
            //Display list2
            list2.display();
            break;
        }

        case 6:
        {
            //Display list3
            list3.display();
            break;
        }

        case 7:
        {
            //Exit
            exit(0);
        }
        
        default:
            printf("\nInvalid option");
            break;
        }
    }
}