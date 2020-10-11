#include <stdio.h>
void bubble_sort(int n,int a[])
{
    int i,j=0,h,flag=1,ans=0;
    while(flag)
    {
        flag=0;
        for(i=n-1;i>0;i--)
        {
            if(a[i]<a[i-1])
            {
                j=a[i];
                a[i]=a[i-1];
                a[i-1]=j;
                flag=1;
                ans++;
            }
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
        bubble_sort(n,a);
        return 0;
}
