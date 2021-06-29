#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) { //配列の要素を順番に出力
    int i;
    for (i=0; i<N; i++) {
        if (i > 0) cout << " "; //隣接する要素の間に1つの空白を出力
        cout << A[i];
    }
    cout << endl;
}

//挿入ソート（0オリジン配列）
void insertionSort(int A[], int N) {
    int j, i, v;
    for (i=1; i<N; i++) {
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
        trace(A, N);
    }
}
int main() {
    int N, i, j;
    int A[100];

    cin >> N;
    for (i=0; i<N; i++) cin >> A[i];

    trace(A, N);
    insertionSort(A, N);
    
    return 0;
}
