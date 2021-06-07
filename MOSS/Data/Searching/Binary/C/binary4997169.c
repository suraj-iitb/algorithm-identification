#include <stdio.h>

    int n, q, a[100000], cnt = 0;
    int find(int t) {
        int mid, r = n, l= 0;
    while (l < r){
        mid = (l + r) / 2;
        if (t == a[mid])
            return 1;
        else if (t > a[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return 0;
}   

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        if (find(x) == 1)
        cnt++;
    }
    printf("%d\n", cnt);
}

