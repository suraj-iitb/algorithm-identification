#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void insertionSort(vector<int> A, int N) {
    REP(i, N) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        rep(i, N - 1) cout << A[i] << " ";
        cout << A[N - 1] << endl;
    }
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    rep(i, N - 1) cout << A[i] << " ";
    cout << A[N - 1] << endl;
    insertionSort(A, N);
}

