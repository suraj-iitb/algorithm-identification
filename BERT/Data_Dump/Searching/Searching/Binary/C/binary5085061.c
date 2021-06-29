#include <stdio.h>

int binarySearch(int);

int n, q,c=0;
int s[1000000],t;

int main()
{
    int i, j, k = 0, a = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for (j = 0; j < q; j++)
    {
        scanf("%d", &t);
        if(binarySearch(t)) c++;
    }

    printf("%d\n", c);

    return 0;
}

int binarySearch(int x)
{
    int left,right,mid;
    int i, j,m=0;
    left=0;
    right=n;
    while(left<right){
        mid=(left+right)/2;
        if(s[mid]==x){
            return 1;
        }
        if(t>s[mid])left=mid+1;
        else if(t<s[mid]) right=mid;
        
    }
    return 0;
}
