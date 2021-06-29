#include <stdio.h>
#define N 100000
#define Q 50000
int main()
{
    int i = 0, r, l, h, a[N], b[Q], n, q, c=0;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d ",&a[i]);
    }
    scanf("%d",&q);
    for(i = 0; i < q; i++)
    {
        scanf("%d ",&b[i]);
    }
    for(i = 0; i < q; i++)
    {
        r = n;
        l = 0;
        while(l < r)
        {
            h = (l+r)/2;
            if(b[i] < a[h])
            {
                r = h;
            }
            else if(b[i] > a[h])
            {
                l = h+1;
            }
            else
            {
                c++;
                break;
            }
        }
    }
    printf("%d\n",c);
    

    return 0;
}
