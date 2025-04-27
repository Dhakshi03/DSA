#include <stdio.h>
#include <stdlib.h>

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