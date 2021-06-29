#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void print(vector<int> &A, int n) {
    for(int i=0; i<n-1; ++i) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);
}

void insertion_sort(vector<int> &A, int n) {

    for(int i=1; i<n; ++i) {
        int v = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A, n);
    }
}


int main() {
    ios::sync_with_stdio(false);
    vector<int> A;
    int n, x;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> x;
        A.push_back(x);
    }
    print(A, n);
    insertion_sort(A, n);

    return 0;
}
