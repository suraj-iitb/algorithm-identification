#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
    cout << A[0];
    for (int i=1; i < N; i++) {
        cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    int v;
    int j;
    for (int i=1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 & A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
    return;
}


int main(){
    int n;
    int A[110];

    cin >> n;
    for (int i=0; i < n; i++) {
        cin >> A[i];
    }
    trace(A, n);
    insertionSort(A, n);
} 
