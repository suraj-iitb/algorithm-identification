#include<stdio.h>
int main(void)
{
    int n,s,r[100],i,j,c,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d ",&r[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(r[j]>r[j+1])
            {
                c = r[j];
                r[j] = r[j+1];
                r[j+1] = c;
                cnt++;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d ",r[i]);
    }
    printf("%d\n%d\n",r[i],cnt);
    return 0;
}
