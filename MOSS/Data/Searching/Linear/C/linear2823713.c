#include <stdio.h>

int cunt(int s,int* S,int t,int* T)
{
    int i,j;
    int cnt=0;
    for(i=0;i<t;i++)
    {
        for(j=0;j<s;j++)
        {
            if(T[i] == S[j])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}


int main(void)
{
    int s,S[10000],t,T[500];
    int i;
    
    scanf("%d",&s);
    for(i=0;i<s;i++) scanf("%d",&S[i]);
    scanf("%d",&t);
    for(i=0;i<t;i++) scanf("%d",&T[i]);
    printf("%d\n",cunt(s,S,t,T));
}

