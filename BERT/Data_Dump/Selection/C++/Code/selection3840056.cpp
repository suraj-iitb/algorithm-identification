#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
    cout << A[0];
    for (int i=1; i < N; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

void selectionSort(int A[], int N) {
    int cnt = 0;
    int minj;
    for (int i=0; i < N-1; i++) {
        minj = i;
        for (int j=i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }

    trace(A, N);
    cout << cnt << endl;
    return;
}


int main(){
    int n;
    int A[110];

    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> A[i];
    }
    selectionSort(A, n);
} 
