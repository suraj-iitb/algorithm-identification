#include <bits/stdc++.h>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

void insertionSort(vector<int>& a, int n) {
    for (int i=1; i<n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        for (int i=0; i<a.size()-1; i++) cout << a[i] << " ";
        cout << a[n-1] <<  endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N-1; i++) cout << A[i] << " ";
    cout << A[N-1] << endl;

    insertionSort(A, N);

    return 0;
}

