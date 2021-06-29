#include <bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = N -1; j > i; j--) {
            if (A[minj] >= A[j]) {
                minj = j;
            }
        }
        
        if (A[i] > A[minj]) {
            cnt++;
            int tmp = A[minj];
            A[minj] = A[i];
            A[i] = tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("%d\n", cnt);
}

int main(void) {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    selectionSort(A, N);
    
    return 0;
}
