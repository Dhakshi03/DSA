//C++ program for sorting

#include <stdio.h>
#include <stdlib.h>
#include "l1q1.h"

/*void bubble(int n, int arr[]);
void selection(int n, int arr[]);
void insertion(int n, int arr[]);*/

int main()
{
    int n;
    printf("Enter the number of values you want to enter: ");
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("\nEnter %d no.: ", i+1);
        scanf("%d",&arr[i]);
    }
    
    while (1)
    {
        int choice;
        printf("\nChose the method of sorting");
        printf("\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Exit");
        printf("\nYour choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                //BUbble sort
                bubble(n, arr);
                break;
            
            case 2:
                //Selection sort
                selection(n, arr);
                break;
            
            case 3:
                //Insertion sort
                insertion(n, arr);
                break;
            case 4:
                //Exit;
                exit(0);
        }
    }
    return 0;
}

/*
//Bubble sort
void bubble(int n, int arr[])
{
    int temp=0;

    for(int i=0; i<n-1;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            } 
        }
    }

    printf("\nThe sorted list is: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

//Selection sort
void selection(int n, int arr[])
{
    for (int i=0; i<n-1; i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    {
        int min=i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j]<arr[min])
            {
                min =j;
            }
        }
        int temp= arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    printf("\nThe sorted list is: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

//Insertion sort
void insertion(int n, int arr[])
{
    for (int i=1; i<n; i++)
    {
        int key= arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }   

    printf("\nThe sorted list is: ");
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }                   
}
*/