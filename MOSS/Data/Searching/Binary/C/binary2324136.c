#include<stdio.h>
int searching(long int a[], long int key, int n)
{
    int left, right, mid;

    left=0;right=n;

    while(left<right)
    {
        mid=(left+right)/2;
        if(a[mid]==key) return 1;
        else if(a[mid]>key) right=mid;
        else left=mid+1;
    }
    return 0;
}
int main()
{
    int n, q, sum=0, i  ;

    long int s[100000], t;

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%ld", &s[i]);

    scanf("%d", &q);
    for(i=0;i<q;i++)
    {
        scanf("%ld", &t);
        if(searching(s, t, n)) sum++;
    }

    printf("%d\n", sum);

    return 0;
}
