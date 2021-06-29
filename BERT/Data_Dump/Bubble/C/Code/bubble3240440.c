#include <stdio.h>
#define N   100
 
int num[101];
 
int Bubble_sort(int num[], int n) {
    int counter = 0;
    int i, j;
 
    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            if (num[j] < num[j-1]) {
                int tmp = num[j];
                num[j] = num[j-1];
                num[j-1] = tmp;
                counter++;
            }
        }
    }
    return counter;
}
 
int main(void) {
    int i, n, count;
    scanf("%d", &n);
 
    for (i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
 
    count = Bubble_sort(num, n);
 
    for (i = 1; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[n]);
    printf("%d\n", count);
 
    return 0;
}
