#include <stdio.h>
#include <stdint.h>

#define MAX 100

int main() {
    int R[MAX];
    char str[8];
    uint8_t n;
    
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }
    for (int i = 0; i< n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", R[i]);
    }
    printf("\n");
    //insert sort
    int tmp, v, j;
    for (int i = 1; i < n; i++) {
        v = R[i];
        j = i -1;
        while (j >= 0 && v < R[j]) {
            R[j + 1] = R[j];
            j--;
        }
        R[j+1] = v;
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", R[j]);
        }
        printf("\n");
    }
    return 0;
    
}
