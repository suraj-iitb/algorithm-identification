#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n,i,j;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     bool flag=1;
     int temp,cont=0;
    for(i=0;flag;i++)
    {
        flag=0;
        for(j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
              temp=a[j];
              a[j]=a[j-1];
              a[j-1]=temp;
              flag=1;
              cont++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(i>0)
            printf(" ",a[i]);

            printf("%d",a[i]);
    }
    printf("\n%d\n",cont);
    return 0;
}

