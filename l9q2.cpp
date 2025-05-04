//Lab9Q2 : Finding the difference in the strengths

#include <cstdio>
#include <cstdlib>
#include <iostream>

void sol()
{
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    int max1, max2;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    max1=max2=-1000000;
    for(int i=0; i<n; i++)
    {
        if (arr[i]>max1)
        {
            max1=arr[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        if (arr[i]!=max1 && arr[i]>max2)
        {
            max2=arr[i];
        }
    }
    
    for (int i=0; i<n; i++)
    {
        if (arr[i]!=max1)
        {
            printf("%d ",arr[i]-max1);
        }
        else
        {
            printf("%d ",arr[i]-max2);
        }
    }
}
int main()
{
    int t,n;
    printf("\nEnter number of test cases: ");
    scanf("%d",&t);
    for (;t>0;t--)
    {
        sol();
    }
}
