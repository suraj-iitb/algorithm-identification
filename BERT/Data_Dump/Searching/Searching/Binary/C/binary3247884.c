#include <stdio.h>

#define Num 200000

int main(void){

    int s[Num], t[Num];
    int n, q, i, j, right, left, mid, count = 0;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf(" %d", &s[i]);
    }

    scanf("%d", &q);
    for (i=0; i<q; i++) {
        scanf(" %d", &t[i]);
    }

    
    for (i=0; i<q; i++) {
        left = 0;
        right = n;
        while (left < right) {
            mid = (right+left)/2;
            if (s[mid] == t[i] || s[mid+1] == t[i]) {
                count++;
                break;
            } else if (t[i] < s[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    printf("%d\n", count);

  return 0;
}
