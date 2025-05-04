#include <cstdio>
#include <cstdlib>

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int k, q;
        scanf("%d %d", &k, &q);
        
        int a[k];
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &a[i]);
        }

        int b[q];
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < q; i++)
        {
            int c_size = b[i];
            int c[c_size];

            for (int j = 0; j < c_size; j++)
            {
                c[j] = 0; 
            }

            int flag = 1;
            while (flag == 1)
            {
                flag = 0;
                for (int j = k - 1; j >= 0; j--)
                {
                    if (a[j] <= c_size)
                    {
                        for (int x = a[j] - 1; x < c_size - 1; x++)
                        {
                            c[x] = c[x + 1];
                        }
                        c_size--;
                        flag = 1;
                    }
                }
            }
            printf("No. of winners: %d ", c_size);
        }
        printf("\n");
    }
    return 0;
}
