#include<iostream>
#include<stdio.h>
using namespace std;

int selectionSort(int A[100], int n) {
    int minj = 0, count = 0;
    for (int i = 0; i < n - 1; i++) {
        minj = i;
        for (int j = i; j < n; j++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            int t = 0;
            t = A[i];
            A[i] = A[minj];
            A[minj] = t;
            count++;
        }
    }
    return count;
}

int main() {
    int A[100];
    int n, count;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    count = selectionSort(A, n);
    
    for (int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;;
    
    return 0;
}
