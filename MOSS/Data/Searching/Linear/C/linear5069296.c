#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000000
#define NMAX 10000
#define QMAX 500

int linear_search(int *, int, int);

int main()
{
    int n, q, i, j, u, cnt;

    scanf("%d",&n);
    if(n > NMAX) {
        exit(1);
    }

    int s[n + 1];
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
        cnt += linear_search(s, t[i], n);
    }

    printf("%d\n",cnt);

    return 0;
}

int linear_search(int *a, int key, int n)
{
    int i = 0;
    a[n] = key;
    while(a[i] != key) {
        i++;
    }
    if(i == n) {
        return 0;
    } 

    return 1;
}
