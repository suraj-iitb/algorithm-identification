#include <bits/stdc++.h>
using namespace std;

void bubblesort(int A[], int N) {
    bool flg = true;
    int cnt = 0;
    while (flg) {
        flg = false;
        for (int j = N - 1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                flg = true;
                cnt++;
                int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
            }
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

    bubblesort(A, N);
    
    return 0;
}
