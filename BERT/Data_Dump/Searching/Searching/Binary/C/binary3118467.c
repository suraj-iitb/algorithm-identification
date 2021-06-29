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
    int r,l,s;
    for(int i=0;i<q;i++)
    {
        r = n;
        l = 0;
        while(l<r)
        {
            s = (r+l)/2;
            if(T[i]==S[s])
            {
                cnt++;
                break;
            }
            else
            {
                if(S[s]<T[i])
                {
                    l = s+1;
                }
                else
                {
                    r = s;
                }
            }
        }
    }
    printf("%d\n",cnt);
    free(T);
    free(S);
}
