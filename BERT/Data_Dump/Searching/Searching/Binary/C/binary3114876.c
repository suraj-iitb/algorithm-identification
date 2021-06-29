#include <stdio.h>
#define NMAX 100001
#define qMAX 50000
 
int S[NMAX];
int T[qMAX];
 
int binarySearch(int n,int key) {
    int left = 0;
    int right = n;
    int mid;
     
    while (left < right) {
        mid = (left + right) / 2;
        if (S[mid] == key) {
            return 1;
        } else if (key < S[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}
 
int main(void)
{
    int n, i, j, q, cnt;
     
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf(" %d", &S[i]);
    }
 
    scanf("%d", &q);
    for (i = 0; i < q; ++i) {
        scanf(" %d", &T[i]);
    }
 
    cnt = 0;
    for (i = 0; i < q; ++i) {
        cnt += binarySearch(n, T[i]);
    }
    printf("%d\n", cnt);
     
    return 0;
}
