#include<stdio.h>
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)


void printArray(int A[], int N) {
    rep(i,N-1)
        printf("%d ", A[i]);
    printf("%d\n",A[N-1]);
}

// 昇順に並び替え後の配列および、交換回数を表示する
void bubbleSort(int A[], int N) {
    int flag = 1;  // 逆順の存在有無
    int head = 0; // 未整列の先頭
    int count = 0;

    while (flag == 1) {
        flag = 0;
        // tailは未整列の末尾
        for(int tail = N -1; tail > head ;tail--) {
            if(A[tail-1] > A[tail]) {
                flag = 1;
                count++;
                int work;
                work = A[tail]; A[tail] = A[tail-1]; A[tail-1] = work;
            }
        }
        head++;
    }
    printArray(A,N);
    printf("%d\n",count);
}


int main() {
    int N;
    int A[100];

    scanf("%d", &N);
    rep(i,N)
        scanf("%d",&A[i]);
    
    bubbleSort(A,N);
    return 0;
}
