#include <iostream>
#include <stdlib.h>
#include <math.h>

void palno(int* num)
{
    int*temp=(int*)malloc(sizeof(int));

    int*rev=(int*)malloc(sizeof(int));
    *rev=0;

    for(*temp=*num;*temp>0;*temp/=10)
    {
        *rev=(*rev)*10+*temp%10;
    }

    if(*rev==*num)
    {
        printf("\nIt is a palindrome");
    }
    else
    {
        printf("\nIt is NOT a palindrome");
    }

    free(temp);
    free(rev);
}

void armno(int*num)
{
    int*temp=(int*)malloc(sizeof(int));
    *temp=*num;
    int*temp2=(int*)malloc(sizeof(int));
    *temp2=*num;

    int*digit=(int*)malloc(sizeof(int));
    *digit=0;

    int*i=(int*)malloc(sizeof(int));
    //counting the number of digits
    for(*temp;*temp>0;*temp/=10)
    {
        *digit+=1;
    }
    
    int*numarr=(int*)calloc(*digit,sizeof(int));

    for(*i=0;*i<*digit;*i+=1)
    {
        numarr[*i]=*temp2%10;
        *temp2/=10;
    }
    int*sum=(int*)malloc(sizeof(int));
    *sum=0;

    for(*i=0;*i<*digit;*i+=1)
    {
        *sum+=pow(numarr[*i],*digit);
    }

    if (*sum==*num)
    {
        printf("\nIt is an armstrong number");
    }
    else
    {
        printf("\nIt is NOT an armstrong number");
    }
    
    free(temp2);
    free(digit);
    free(sum);
}

void perno(int*num)
{
    int*temp=(int*)malloc(sizeof(int));
    *temp=*num;

    int*sum=(int*)malloc(sizeof(int));
    *sum=0;

    int*i=(int*)malloc(sizeof(int));

    for(*i=1;*i<*num;*i+=1)
    {
        if(*temp%(*i)==0)
        {
            *sum+=*i;
        }
    }

    if(*sum==*num)
    {
        printf("\nIt is a perfect number");
    }
    else
    {
        printf("\nIt is NOT a perfect number");
    }

    free(temp);
    free(i);
    free(sum);
}