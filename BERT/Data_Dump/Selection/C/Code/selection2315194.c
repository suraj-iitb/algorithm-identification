#include<stdio.h>
int main()
{
    int n, i, j, minj, temp, count=0;
    int a[100];

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    for(i=0;i<n-1;i++)
    {
        minj=i;
        for(j=i;j<n;j++)
            if(a[j]<a[minj]) minj=j;
        if(minj!=i)
        {
            temp=a[i];
            a[i]=a[minj];
            a[minj]=temp;
            count++;
        }
    }

    for(i=0;i<n-1;i++)
        printf("%d ", a[i]);
    printf("%d\n", a[i]);
    printf("%d\n", count);

    return 0;
}
