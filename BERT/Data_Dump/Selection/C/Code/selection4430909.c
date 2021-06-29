#include<stdio.h>

//選択ソート
int selectionSort(int N, int A[]) {
    
    int i, j, min, cnt = 0, tmp;
    
    for (i = 0; i < N - 1; i++) {
        
        min = i;
        
        //最小値の位置決定
        for (j = i; j < N; j++){
            if (A[j] < A[min]) min = j;
        }
        
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
        
        if (i != min) cnt++;
    }
    return cnt;
}

int main(void) {
    int cnt, N, A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    cnt = selectionSort(N, A);
    
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    
    printf("\n");
    printf("%d\n", cnt);

}
    
