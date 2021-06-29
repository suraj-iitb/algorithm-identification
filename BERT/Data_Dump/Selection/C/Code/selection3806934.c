#include <stdio.h>
void selection_sort(int n,int a[])
{
    int i,j,mins,ans=0,h;
    for(i=0;i<=n-1;i++)
    {
        mins=i;
        for(j=i;j<=n-1;j++)
        {
            if(a[j]<a[mins])
            {
                mins=j;
            }
        }
        if(a[i]!=a[mins])
        {
         h=a[i];
        a[i]=a[mins];
        a[mins]=h;
        ans++;
        }
    }
     for(h=0;h<n;h++)
        {
            if(h>0)
                printf(" ");
            printf("%d",a[h]);
        }
        printf("\n");
        printf("%d\n",ans);
}
int main()
{
    int i,n,a[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        selection_sort(n,a);
        return 0;
}

