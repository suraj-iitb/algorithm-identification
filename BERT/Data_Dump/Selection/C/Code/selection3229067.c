#include<stdio.h>
int main(void)
{
    int n,s,r[100],i,j,c,cnt=0,min;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i;j<n;j++)
        {
            if(r[min] > r[j])
            {
                min = j;
            }
        }
        if(min != i) cnt++;
        c = r[i];
        r[i] = r[min];
        r[min] = c;
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d ",r[i]);
    }
    printf("%d\n%d\n",r[i],cnt);
    return 0;
}
