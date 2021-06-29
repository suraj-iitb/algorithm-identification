#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000

typedef struct {
    char mark;
    int value;
} CARD;

CARD A[N];

int partition(int p, int r) {
    
    int x = A[r].value, i = p - 1, j, tmp_m, tmp_v;
    
    for (j = p; j < r; j++) {
        if (A[j].value <= x) {
            i++;
            tmp_m = A[i].mark;
            tmp_v = A[i].value;
            A[i].mark = A[j].mark;
            A[i].value = A[j].value;
            A[j].mark = tmp_m;
            A[j].value = tmp_v;
        }
    }
    tmp_m = A[i + 1].mark;
    tmp_v = A[i + 1].value;
    A[i + 1].mark = A[r].mark;
    A[i + 1].value = A[r].value;
    A[r].mark = tmp_m;
    A[r].value = tmp_v;
    
    return i + 1;
}

void quicksort(int p, int r) {
    int q;
    if (p < r) {
        q = partition(p , r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}

int main(void){
    int i, j, n, flg = 0 , stable[N]={}, k;
    CARD bef[N];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
      scanf("%*c%c%d", &A[i].mark, &A[i].value);
      bef[i].value = A[i].value;
      bef[i].mark = A[i].mark;
    }

    quicksort(0, n - 1);
    
    flg = 0;
    
    for (i = 0; i < n; i++) {
        j = 0;
        k = 0;
        while (j <= stable[A[i].value]) {
            if (bef[k].value == A[i].value) {
                j++;
            }
            k++;
        }
        stable[A[i].value]++;
        j--;
        if(bef[j].mark != A[i].mark) {
            flg = 1;
            break;
        }
    }
    
    if(flg) printf("Not stable\n");
    else printf("Stable\n");
    
    for (i = 0; i < n; i++) {
        printf("%c %d\n", A[i].mark, A[i].value);
    }
    
    return 0;
}


