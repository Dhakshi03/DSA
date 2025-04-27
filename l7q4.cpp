#include <cstdio>
#include <cstdlib>
#define SIZE 50

class stringstack
{
    char stck[SIZE];
    int top;

public:
    stringstack()
    {
        top = -1;
    }

    void solve(char arr[])
    {
        int count = 0;

        for (int i = 0; arr[i] != '\0'; i++)
        {
            if (arr[i] == '+')
            {
                count++;
                if (count == 1)
                    top--;
            }
            else
            {
                stck[++top] = arr[i];
            }
        }

        printf("The result is: ");
        for (int i = 0; i <= top; i++)
            printf("%c", stck[i]);
        printf("\n");
    }
};

int main()
{
    char arr[SIZE];
    stringstack s;

    printf("Enter the string: ");
    scanf("%s", arr);

    s.solve(arr);

    return 0;
}
