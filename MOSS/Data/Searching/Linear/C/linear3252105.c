#include <stdio.h>
#define N 10000
#define Q 500
int main()
{
    int i = 0, j, a[N], b[Q], n, q, c=0;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d ",&a[i]);
        i++;
    }
    i=0;
    scanf("%d",&q);
    while(i<q)
    {
        scanf("%d ",&b[i]);
        i++;
    }
    for(i = 0; i < q; i++)
    {
        j = 0;
        a[n] = b[i];
        while(a[j] != b[i])
        {
            j++;
        }
        if(j != n) c++;
    }
    printf("%d\n",c);
    

    return 0;
}
