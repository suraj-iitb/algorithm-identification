#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,q,cnt =0;
    scanf("%d",&n);
    int *S = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&S[i]);
    scanf("%d",&q);
    int *T = malloc(sizeof(int)*q);
    for(int i=0;i<q;i++) scanf("%d",&T[i]);
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(S[j]==T[i])
            {
                cnt ++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    free(T);
    free(S);
}
