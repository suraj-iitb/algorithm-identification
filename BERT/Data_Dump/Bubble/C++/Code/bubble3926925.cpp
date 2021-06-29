#include <stdio.h>
int bubblesort(int a[],int n)
{
    int i,j,temp,ans=0;
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                ans++;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",ans);
    return ans;
}

int main()
{
    int n,i,j;
    int a[100];

    scanf("%d",&n);
    for(i=0; i<n; i++)  scanf("%d",&a[i]);

    bubblesort(a,n);

    return 0;
}

