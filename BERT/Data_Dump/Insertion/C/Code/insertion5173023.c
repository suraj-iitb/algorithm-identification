#include <stdio.h>

int main()
{
    int s,i,j,n,f,h,key;
    int a[100];
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
        scanf("%d",&a[h]);
    }
    for(f=0;f<n;f++)
        {
            printf("%d",a[f]);
            if(f==n-1) break;
            printf(" ");
        }
        printf("\n");
        for(i=1;i<=n-1;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>key)
            {
                a[j+1]=a[j];
                j--;
                a[j+1]=key;
            }
            for(f=0;f<n;f++)
            {
                printf("%d",a[f]);
                if(f==n-1) break;
                printf(" ");
            }
            printf("\n");
        }
return 0;

}

