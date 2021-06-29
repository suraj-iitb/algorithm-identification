#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX 100

int main() {
    uint8_t R[MAX];
    uint8_t n;
    char str[8];
    
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }
    int flag = 1;
    int cnt = 0;
    uint8_t tmp;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--) {
            if (R[j] < R[j-1]) {
                tmp = R[j];
                R[j] = R[j-1];
                R[j-1] = tmp;
                flag = 1;
                cnt += 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", R[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
    
}
