#include <stdio.h>
#include <stdlib.h>

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