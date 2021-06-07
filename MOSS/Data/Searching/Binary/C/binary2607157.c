#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int left, right, mid;
    left = 0;
    right = n;
    
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] == key){
            return 1;
        }
        else if (key < a[mid]){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    
    int i, n, a[100000], q, key, sum = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; ++i) {
        scanf("%d", &key);
        if (binarySearch(a, n, key)) sum = sum + 1;
    }
    
    printf("%d\n", sum);
    
    return 0;
}
