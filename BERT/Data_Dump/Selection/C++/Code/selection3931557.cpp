#include <stdio.h>
#include <string.h>
int selectionsort(int a[],int n)
{
    int i,j,minj,temp,ans=0;
    for(i=0; i<n; i++)
    {
        minj=i;
        for(j=i+1; j<n; j++)
        {
            if(a[minj]>a[j])
            {
                minj=j;
            }
        }
        temp=a[minj];
        a[minj]=a[i];
        a[i]=temp;
        if(i!=minj)
            ans++;
    }
    return ans;
}

int main()
{
    int i,n,ans;
    int a[110];
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    ans=selectionsort(a,n);

    for(i=0; i<n; i++)
    {
        if(i!=0)   printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",ans);

    return 0;
}

