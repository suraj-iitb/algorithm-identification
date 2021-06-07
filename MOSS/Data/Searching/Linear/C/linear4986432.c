#include <stdio.h>
int main()
{
    int count=0, n, s[10000], t, q[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &q[i]);
        for (int j = 0; j < n; j++)
        {
            
        if (s[j] == q[i])
        {
            count++;
            break;
        }
        }
        
    }
    printf("%d\n", count);

    return 0;
}
