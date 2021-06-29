#include <stdio.h>
void insertion_sort(int n,int a[])
{
    int i,j,h;
    for(i=1;i<=n-1;i++)
    {
        for(h=0;h<n;h++)
        {
            if(h>0)
                printf(" ");
            printf("%d",a[h]);
        }
        printf("\n");
        int v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
    }
     for(h=0;h<n;h++)
        {
            if(h>0)
                printf(" ");
            printf("%d",a[h]);
        }
        printf("\n");
}
int main()
{
    int i,n,a[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        insertion_sort(n,a);
        return 0;
}

