#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a[101];
    int i=0,j=0,q=0;
    int p=0,t;
    scanf("%d",&n);
        for(q=0;q<n;q++)
        {
            scanf("%d",&a[q]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    p=p+1;
                }
            }
        }
        for(int i = 0;i<n;i++)
             {
               if(i<n-1)
                 printf("%d ",a[i]);
               else printf("%d",a[i]);
             }
        printf("\n");
        printf("%d\n",p);
    return 0;
}
