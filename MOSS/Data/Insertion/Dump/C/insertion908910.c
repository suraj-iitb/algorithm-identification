#include <stdio.h>

#define N_MAX 100
int suuretu[N_MAX]; // sortする数列

int main() {
    int N; //数列の長さ
    int i, j, k, tmp, val;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &suuretu[i]);
    }
    for (i = 0; i < N; i++) {
        val = suuretu[i];
        for (j = i; j >= 0; j--) {
            if (val < suuretu[j]) {
                tmp = suuretu[j];
                suuretu[j] = val;
                suuretu[j+1] = tmp;
            }
        }
        for (k = 0; k < N; k++) {
            printf("%d", suuretu[k]);
            if (k == N - 1) {printf ("\n");}
            else {printf(" ");}
        }
    }
    return 0;
}
