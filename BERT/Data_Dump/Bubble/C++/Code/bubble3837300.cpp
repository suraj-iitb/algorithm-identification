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

void bubbleSort(int A[], int N) {
    int v;
    int flag = 1;
    int cnt = 0;
    
    while (flag > 0) {
        flag = 0;
        for (int j=N-1; j > 0; j--) {
            v = A[j];
            if (A[j - 1] > v) {
                A[j] = A[j - 1];
                A[j - 1] = v;
                v = A[j];
                flag = 1;
                cnt++;
            }
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
    bubbleSort(A, n);
} 
