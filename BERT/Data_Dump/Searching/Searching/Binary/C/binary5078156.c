#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000000
#define NMAX 100000
#define QMAX 50000
#define NOT_FOUND 0

int binary_search(int *, int, int);

int main()
{
    int n, q, i, cnt;

    scanf("%d",&n);
    if(n > NMAX) {
        exit(1);
    }

    int s[n];
    for(i = 0 ; i < n ; i++) {
        scanf("%d", &s[i]);
        if(s[i] < 0 || s[i] > MAX) {
            exit(2);
        }
    }

    scanf("%d",&q);
    if(q > QMAX) {
        exit(3);
    }

    int t[q];
    for(i = 0 ; i < q ; i++) {
        scanf("%d", &t[i]);
        if(t[i] < 0 || t[i] > MAX) {
            exit(4);
        }
        if(i >= 1) {
            if(t[i] == t[i - 1]) {
                exit(5);
            }
        }
    }

    for(i = 0 ; i < q ; i++) {
        cnt += binary_search(s, t[i], n);
    }

    printf("%d\n",cnt);

    return 0;
}

int binary_search(int *a, int key, int n)
{
    int l, r, mid;
    l = 0 ;
    r = n ;
    while(l < r) {
        mid = (l + r) / 2 ;
        if(key == a[mid]) {
            return 1 ;
        } else if(key > a[mid]) {
            l = mid + 1 ;
        } else if(key < a[mid]) {
            r = mid ;
        }
    }

    return NOT_FOUND;
}
