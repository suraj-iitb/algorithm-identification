#include<stdio.h>

int search(int list[], int n, int key) {
    int right = n;
    int left = 0;
    int mid = 0;
    
    while(left < right) {
        mid = (left + right) / 2;
        if(list[mid] == key) {
            return 1;
        } else if(key < list[mid]) {
            right = mid;
        } else if(key > list[mid]) {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n, q, i, sum = 0, key, A[1000000];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    
    for(i = 0; i < q; i++) {
        scanf("%d", &key);
        if(search(A, n, key)) {
            sum++;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
