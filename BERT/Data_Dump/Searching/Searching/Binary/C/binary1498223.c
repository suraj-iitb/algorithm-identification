#include <stdio.h>
int main()
{
    int a,b,i;
    int min,max,mid,cnt=0;
    scanf("%d",&a);
    int x[a];
    for(i=0;i<a;i++)
    {
        scanf("%d",&x[i]);
    }
    scanf("%d",&b);
    int y[b];
    for(i=0;i<b;i++)
    {
        scanf("%d",&y[i]);
        min=0;max=a;
        while(min<max)
        {
            mid=(min+max)/2;
            if(y[i]==x[mid])
            {
                cnt++;
                break;
            }
            else if (y[i]<x[mid])
            {
                max=mid;
            }
            else
            {
                min=mid+1;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
