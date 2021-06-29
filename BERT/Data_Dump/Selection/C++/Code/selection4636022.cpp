#include <stdio.h>

#define swap(a,b) {int t=a;a=b;b=t;}

int select_sort(int A[], int N) {
    int cnt=0;
    for(int i=0;i<N;i++) {
        int minj = i;
        for (int j=i+1;j<N;j++) {
            if(A[j]<A[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(A[minj], A[i]);
            cnt++;
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
    int cnt = select_sort(A, N);
    for(int i=0;i<N;i++) {
        printf("%d%c", A[i], i==N-1?'\n':' ');
    }
    printf("%d\n", cnt);
    return 0;
}

