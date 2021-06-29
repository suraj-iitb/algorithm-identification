#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
    for(int i=0; i<N; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    int j, i, v;
    for(int i=1; i<N; i++) {
        v = A[i]; //値を一時保存
        j = i - 1; //ソート済の部分列より挿入位置を探す
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main(){
    int N, i, j;
    int A[100];
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    trace(A, N);
    insertionSort(A, N);
    return 0;
}
