#include<stdio.h>

int binarySearch(int,int);
    
int S[100000];

int main()
{
    int n, q, i, cnt = 0, flag;
    int T[100000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);
        flag = binarySearch(n, T[i]);
        if (flag == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}

int binarySearch(int n,int key)
{
    int l=0,mid,r=n;
    while(l<r)
    {
        mid = (l+r)/2;
        if(S[mid] == key)return 0;
        else if(key < S[mid]) r = mid;
        else l = mid + 1;
    }
    return 1;
}

