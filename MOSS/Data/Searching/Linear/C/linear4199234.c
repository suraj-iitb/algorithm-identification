
#include <stdio.h>

int main()
{
    int m,n,i,sum = 0,j;
    int S[10000],Q[500];
    scanf("%d",&m);
    for(i = 0;i < m;i++)
    {
        scanf("%d",&S[i]);
    }
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&Q[i]);
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            if(Q[i]==S[j])
            {
                sum++;
                break;
            }
        }
    }
    printf("%d\n",sum);
}


