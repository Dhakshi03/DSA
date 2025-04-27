#include <iostream>
#include <stdlib.h>
#include "l2q1.h"

void palno(int* num);
void armno(int* num);
void perno(int* num);

int main()
{
    int*choice=(int*)malloc(sizeof(int));
    while(1)
    {
        printf("\n1.Palindrome\n2.Armstrong\n3.Perfect\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",choice);
        
        int*num=(int*)malloc(sizeof(int));

        switch(*choice)
        {
            case 1:
                printf("\nEnter your number: ");
                scanf("%d",num);

                palno(num);
                break;
            
            case 2:
                printf("\nEnter your number: ");
                scanf("%d",num);

                armno(num);
                break;
            
            case 3:
                printf("\nEnter your number: ");
                scanf("%d",num);

                perno(num);
                break;

            case 4:
                free(num);
                free(choice);
                exit(0);
        }
        free(num);
    }

    return 0;
}