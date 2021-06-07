#include<stdio.h>

int n, S[100000];

int binarySearch(int key) {
    int left = 0, right = n, mid;
    
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

int main() {
    int q, key, ans = 0;
    int i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        
        if (binarySearch(key)) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}

