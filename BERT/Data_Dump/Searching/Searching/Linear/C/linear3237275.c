#include<stdio.h>

int linearSearch(int n, int S[], int key) {
    int i = 0;
    
    S[n] = key;
    
    while (S[i] != key) {
        i++;
    }
    
    return i != n;
}

int main() {
    int n, S[10000], q, key, ans = 0;
    int i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        
        if (linearSearch(n, S, key)) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

