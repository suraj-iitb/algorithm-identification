#include <bits/stdc++.h>

using namespace std;

void insertionSort(int A[], int N) { // N個の要素を含む0-オリジンの配列A
        int j, v;
        for(int i = 0; i < N; i++) {
                v = A[i];
                j = i - 1;
                while (j >= 0 &&  A[j] > v) {
                        A[j+1] = A[j];
                        j--;
                        A[j+1] = v;
                }
                for(int k = 0; k < N; k++) {
                        if(k != N-1) {
                                printf("%d ", A[k]);
                        }else{
                                printf("%d\n", A[k]);
                        }
                }
        }
}

int main(int argc, char const *argv[]) {
        int N;
        cin >> N;
        int a[N];
        for(int i = 0; i < N; i++ ) cin >> a[i];
        insertionSort(a, N);
        return 0;
}

