#include <iostream>
#include <bits/stdc++.h>
#define MAX_NUM 10001
#define MAX_SIZE 2000010
using namespace std;



void countingSort(unsigned short A[], unsigned short B[], int n, int k) {
    int C[k];
    for (int i=0; i < k; i++) C[i] = 0;
    for (int j=0; j < n; j++) C[A[j]]++;
    for (int i=1; i < k; i++) C[i] += C[i - 1];
    for (int j=n-1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main(){
    int n;
    unsigned short *A, *B;
    cin >> n;
    A = (unsigned short *) malloc(sizeof(short) * n + 1);
    B = (unsigned short *) malloc(sizeof(short) * n + 1);
    for (int i=0; i < n; i++) cin >> A[i];
    countingSort(A, B, n, MAX_NUM);
    for (int i=0; i < n-1; i++) cout << B[i] << " ";
    cout << B[n -1] << endl;
    return 0;
} 
