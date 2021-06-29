#include<stdio.h>

int main(void)
{
    int n, q;
    int array_n[10001], array_q[501];
    int i, j;
    int count=0;

    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &array_n[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++)
    {
        scanf("%d", &array_q[i]);
    }

    for(i=0; i<q; i++)
    {
        for(j=0; j<n; j++)
        {
            if(array_n[j] == array_q[i])
            {
                count++;
                break;
            }
        }
    }
    
    printf("%d\n", count);

  return 0;
}

