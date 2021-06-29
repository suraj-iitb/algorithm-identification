#include<stdio.h>

int main() {
    int n, q, i, j, key, a;
    int left, mid, right;
    int s[100000];
    int t[50000];
    int count = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    
    scanf("%d", &q);
    for (i = 0; i < q; i++)
        scanf("%d", &t[i]);
    
    for (i = 0; i < q; i++) {
        left = 0;
        right = n;
        a = 0;
        key = t[i];
        j = 0;
        while (left < right && a == 0) {
            mid = (left + right) / 2;
            if (s[mid] == key)
                a = 1;
            else if (key < s[mid])
                right = mid;
            else
                left = mid + 1;
        }
        if (a == 1)
            count++;
    }
    
    printf("%d\n", count);
    
}
