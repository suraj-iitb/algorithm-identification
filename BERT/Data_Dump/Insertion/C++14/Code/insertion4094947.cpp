#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &A) {
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i] << ((i+1==A.size())?"\n":" ");
    }
}

void insertionSort (vector<int> &A) {
    int N = A.size();
    for (int i = 1; i < N; i++) {
        print(A);
        int v = A[i], j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    insertionSort(A);
    print(A);
}
    
