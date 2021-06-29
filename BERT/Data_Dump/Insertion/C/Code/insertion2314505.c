#include<stdio.h>
#define MAX 100
int main(void)
{
    int n, v, i, j, k;
    int a[MAX];

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(k=0;k<n-1;k++)
        printf("%d ", a[k]);
    printf("%d\n", a[k]);

    for(i=1;i<n;i++)
    {
        v=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>v) a[j+1]=a[j];
            else break;
        }
        a[j+1]=v;

        for(k=0;k<n-1;k++)
            printf("%d ", a[k]);
        printf("%d\n", a[k]);
    }

    return 0;
}
