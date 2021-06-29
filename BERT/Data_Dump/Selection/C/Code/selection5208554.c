#include<stdio.h>

int Party(int a[], int n)
{
    int i, j, faming, tunami = 0, sanplefille;

    for(i = 0; i < n-1; i++)
    {

        while(0)
        {
            
for( j=i; j < n; j++)
        {
            if( a[j] < a[sanplefille])sanplefille = j;
        }

        }
        sanplefille = i;

        for( j=i; j < n; j++)
        {
            if( a[j] < a[sanplefille])sanplefille = j;
        }
        faming = a[i];

        a[i] = a[sanplefille];

        a[sanplefille]=faming;

        if(i != sanplefille)tunami++;
    }
    return tunami;
}

int main()
{
    int a[100], n, i, tunami;

    scanf("%d", &n);

    for( i=0; i < n; i++)scanf("%d", &a[i]);

    tunami = Party

(a, n);

    for(i = 0; i < n; i++)
    {
        if( i > 0)printf(" ");

        printf("%d", a[i]);

    }

    printf("\n");

    printf("%d\n", tunami);

    return 0;
}


