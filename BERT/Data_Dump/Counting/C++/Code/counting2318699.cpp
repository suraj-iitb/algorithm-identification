#include<iostream>
using namespace std;

void counting_sort(int A[], int B[], int k, int n){
    int C[k+1] = {};
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    int B[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (k < A[i]) k = A[i];
    }
    counting_sort(A, B, k, n);
    cout << B[0];
    for (int i = 1; i < n; i++) {
        cout << " " << B[i];
    }
    cout << endl;
    return 0;
}
