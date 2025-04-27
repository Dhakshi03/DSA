//Searching for an element

#include <stdio.h>
#include <stdlib.h>
#include "l1q1.h"
#include "l1q2.h"

/*
void linear(int n, int arr[], int num);
int binary(int n, int arr[], int num);
*/

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

    int num;
    printf("\nEnter the element you want to search for: ");
    scanf("%d",&num);

    //sorting
    bubble(n,arr);
    /*
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
    */
    
    while (1)
    {
        int choice;
        printf("\nChose the method of searching");
        printf("\n1.Linear search\n2.Binary search\n3.Exit");
        printf("\nYour choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                //Linear search
                linear(n, arr, num);
                break;
            }
            case 2:
            {
                //BInary search
                int pos = binary(n, arr, num);
                if (pos==-1)
                {
                    printf("\nElement NOT found!");
                }
                else
                {
                    printf("\nELement found at %d position",pos+1);
                }
                break;
            }
            case 3:
            {
                //Exit;
                exit(0);
            }
        }
    }
    return 0;
}

/*
//Linear search
void linear(int n, int arr[], int num)
{
    for (int i=0; i<n; i++)
    {
        if (arr[i]==num)
        {
            printf("\nElement found!");
            return;
        }
    }
    printf("\nElement NOT found");
}

//Binary search
int binary(int n, int arr[], int num)
{
    int start=0;
    int end=n-1;

    //searching
    while (start<=end)
    {
        int mid=(start+end)/2;
        if (num==arr[mid])
        {
            return mid;
        }
        else if (num<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
*/