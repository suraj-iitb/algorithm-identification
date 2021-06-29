#include <stdio.h>

#define swap(a,b) {int t;t=a;a=b;b=t;}

int bubble_sort(int A[], int N) {
    int cnt =0;
    for(int i=0;i<N;i++) {
        for(int j=N-1;j>i;j--){
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N, A[100+1];
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    int cnt = bubble_sort(A,N);
    for(int i=0;i<N;i++) {
        printf("%d%c", A[i], i==N-1?'\n':' ');
    }
    printf("%d\n", cnt);

    return 0;
}
