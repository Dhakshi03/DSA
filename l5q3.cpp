#include <cstdio>
#include <cstdlib>

class roundrobin
{
    struct node
    {
        int data;
        struct node* next;
    };

    struct node*head=NULL;

    public:
    
    void insprocess(int num)
    {
        struct node*newnode=(node*)malloc(sizeof(node));
        newnode->data=num;
    
        struct node *temp=head;
        if(head==NULL)
        {
            newnode->next=newnode;
            head=newnode;
        }
        else
        {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        }
    }

    void execute(int time)
    {
        if (head == NULL)
        {
            printf("\nNo processes to execute.\n");
            return;
        }

        struct node *temp=head;
        struct node *prev=NULL;

        while(head!=NULL)
        {
            temp->data=(temp->data)-time;
            if(temp->data<=0)
            {

                if (temp->next == temp)  // Last process in the list
                {
                    free(temp);
                    head = NULL;
                    return;
                }

                if(temp==head)
                {
                    //deleting the node when head is pointing to it
                    struct node*todel=head;
                    while(todel->next!=head)
                    {
                        todel=todel->next;
                    }
                    todel->next=head->next;
                    head=head->next;
                    free(temp);
                    temp=head;
                }
                else
                {
                    //deleting the node when head is not pointing to it
                    prev->next=temp->next;
                    temp=prev->next;
                }
                
            }
            else
            {
                prev=temp;
                temp=temp->next;
                head=temp;
            }

            if(head!=NULL)
            {
            struct node* display=head;
            while(display->next!=head)
            {
                printf("%d->",display->data);
                display=display->next;
            }
            printf("%d",display->data);
            }
            else
            {
                printf("\nQueue empty!");
            }
            printf("\n");
        }
    }

};

int main()
{
    roundrobin rr;
    int num, choice, time;

    while(1)
    {
        printf("\n1.Insert process\n2.Execute\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter number: ");
                scanf("%d",&num);
                rr.insprocess(num);
                break;
            }

            case 2:
            {
                printf("\nEnter time: ");
                scanf("%d",&time);
                rr.execute(time);
                break;
            }

            case 3:
            {
                exit(0);
            }
        }
    }
    return 0;
}