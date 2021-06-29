#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N-1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> A, int N) {
    int j, v;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        display(A, N);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    display(a, n);
    insertionSort(a, n);
    return 0;
}
