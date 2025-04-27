//List ADT using arrays

#include <iostream>
#include <cstdlib>
#include <cstdio>

class list
{
    int list[5]={1,2,3,4,5};
    int size=5; 

public:
    void insertbeg(int num){
        if(size >= 5) {
            printf("\nList is full, cannot insert at the beginning!\n");
            return;
        }
        for (int i = size; i > 0; i--){
            list[i] = list[i - 1];
        }
        list[0] = num;
        size++;
    }
    void insertend(int num){
        if(size >= 5) {
            printf("\nList is full, cannot insert at the end!\n");
            return;
        }
        list[size] = num;
        size++;
    }
    void insertpos(int num, int pos){
        if(size >= 5) {
            printf("\nList is full, cannot insert at position %d!\n", pos);
            return;
        }
        if (pos > size || pos < 1) {
            printf("\nInvalid position!\n");
            return;
        }
        for (int i = size; i >= pos; i--){
            list[i] = list[i - 1];
        }
        list[pos - 1] = num;
        size++; 
    }
    void delbeg(){
        for (int i=0; i<5 ; i++)
        {
            list[i]=list[i+1];
        }
        list[0]=0;
        size--;
    }
    void delend(){
        list[size]=0;
        size--;
    }
    void delpos(int pos){
        for (int i=pos; i<5; i++)
        {
            list[i]=list[i+1];
        }
        list[size]=0;
        size--;
    } 
    void search(int num){
        for (int i=0; i<5; i++)
        {
            if (list[i]==num){
                printf("\nNumber found!");
                return;
            }
        }
        printf("\nNumber not found!");
        
    }  
    void display(){
        printf("\n");
        if(size == 0) {
            printf("\nList is empty!\n");
            return;
        }
        printf("\nList: ");
        for (int i = 0; i < size; i++){
            printf("%d ", list[i]);
        }
    }
    
    void rotate(int k){ //To DO
        for (int i=0; i<k; i++){
            int temp=list[4];
            for (int i=4; i>=0; i--)
            {
                list[i+1]=list[i];
            }
            list[0]=temp;
        }
    }
};

int main()
{
    list obj;
    int choice, num, pos, k;

    while (1)
    {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at a position");
        printf("\n1.Delete at beginning\n2.Delete at end\n3.Delete at a position");
        printf("\n7.Search for an element\n8.Display\n9.Rotate\n10.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            {
                printf("\nEnter number to insert: ");
                scanf("%d",&num);
                obj.insertbeg(num);
                printf("\nNumber entered successfully!");
                break;
            }
            case 2:
            {
                printf("\nEnter number to insert: ");
                scanf("%d",&num);
                obj.insertend(num);
                printf("\nNumber entered successfully!");
                break;
            }
            case 3:
            {
                printf("\nEnter number to insert: ");
                scanf("%d",&num);
                printf("\nEnter position to insert in: ");
                scanf("%d",&pos);
                obj.insertpos(num, pos);
                printf("\nNumber entered successfully!");
                break;
            }
            case 4:
            {
                obj.delbeg();
                printf("\nNumber deleted successfully!");
                break;
            }
            case 5:
            {
                obj.delend();
                printf("\nNumber deleted successfully!");
                break;
            }
            case 6:
            {
                printf("\nEnter position to delete from: ");
                scanf("%d",&pos);
                obj.delpos(pos);
                printf("\nNumber deleted successfully!");
                break;
            }
            case 7:
            {
                printf("\nEnter number to search for: ");
                scanf("%d",&num);
                obj.search(num);
                break;
            }
            case 8:
            {
                obj.display();
                break;
            }
            case 9:
            {
                printf("\nEnter the number of times you want to rotate it: ");
                scanf("%d",&k);
                obj.rotate(k);
                break;
            }
            case 10:
            {
                exit(0);
            }
        }
    }
}