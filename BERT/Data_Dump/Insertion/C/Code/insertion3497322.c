#include <stdio.h>

/* 配列の要素を順番に出力 */
void trace(int A[],int N) {
    int i;
    for(i=0;i<N;i++) {
        /* 隣接する要素の間に1つの空白を出力 */
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
	puts("");
}

/* 挿入ソート(0オリジン配列) */
void insertionSort(int A[], int N) {
    int i,j,v;
    for(i=1;i<N;i++) {
        v=A[i];
        j=i-1;
        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }
}

int main(void)
{
    int N, i;
    int A[100];
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    
    trace(A,N);
    insertionSort(A,N);
    return 0;
}
