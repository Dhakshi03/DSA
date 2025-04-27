#include <cstdio>
#include <cstdlib>

class DoublyList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    } *head = NULL, *tail = NULL;

public:
    void insertbeg(int num)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->prev = NULL;

        if (!head)
        {
            newNode->next = NULL;
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertend(int num)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;

        if (!head)
        {
            newNode->prev = NULL;
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertpos(int num, int pos)
    {
        if (pos < 1)
        {
            printf("\nInvalid position!\n");
            return;
        }
        if (pos == 1)
        {
            insertbeg(num);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp)
        {
            printf("\nPosition out of range!\n");
            return;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;
    }

    void delbeg()
    {
        if (!head)
        {
            printf("\nList is empty!\n");
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head)
            head->prev = NULL;
        else
            tail = NULL;

        free(temp);
    }

    void delend()
    {
        if (!head)
        {
            printf("\nList is empty!\n");
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = NULL;
        else
            head = NULL;

        free(temp);
    }

    void delpos(int pos)
    {
        if (!head || pos < 1)
        {
            printf("\nInvalid operation!\n");
            return;
        }

        if (pos == 1)
        {
            delbeg();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos && temp; i++)
            temp = temp->next;

        if (!temp)
        {
            printf("\nPosition out of range!\n");
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        free(temp);
    }

    void search(int num)
    {
        Node *temp = head;
        int pos = 1;

        while (temp)
        {
            if (temp->data == num)
            {
                printf("\nElement found at position %d", pos);
                return;
            }
            temp = temp->next;
            pos++;
        }

        printf("\nElement not found!");
    }

    void display()
    {
        if (!head)
        {
            printf("\nList is empty!\n");
            return;
        }

        Node *temp = head;
        printf("\nList: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyList obj;
    int choice, num, pos;

    while (1)
    {
        printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at a position");
        printf("\n4.Delete at beginning\n5.Delete at end\n6.Delete at a position");
        printf("\n7.Search for an element\n8.Display\n9.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number to insert: ");
            scanf("%d", &num);
            obj.insertbeg(num);
            break;
        case 2:
            printf("\nEnter number to insert: ");
            scanf("%d", &num);
            obj.insertend(num);
            break;
        case 3:
            printf("\nEnter number to insert: ");
            scanf("%d", &num);
            printf("\nEnter position to insert in: ");
            scanf("%d", &pos);
            obj.insertpos(num, pos);
            break;
        case 4:
            obj.delbeg();
            break;
        case 5:
            obj.delend();
            break;
        case 6:
            printf("\nEnter position to delete from: ");
            scanf("%d", &pos);
            obj.delpos(pos);
            break;
        case 7:
            printf("\nEnter number to search for: ");
            scanf("%d", &num);
            obj.search(num);
            break;
        case 8:
            obj.display();
            break;
        case 9:
            exit(0);
        }
    }
}