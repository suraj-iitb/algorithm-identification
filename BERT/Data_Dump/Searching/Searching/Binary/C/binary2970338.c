#include<stdio.h>
#define n_max 10000000
#define q_max 10000000

int Binary(int);
int S[n_max], T[q_max], n;

int main() {
    int i, q, count = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
        if (Binary(T[i]))count++;
    }
    
    printf("%d\n", count);
    return 0;
}

int Binary(int x) {
    int left = 0, right = n, mid;
    
    while (left<right) {
        mid = (left + right)/2;
        if (x == S[mid])return 1;
        else if (x > S[mid])left = mid +1;
        else if (x < S[mid])right = mid;
    }
    return 0;
}

