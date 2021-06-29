#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void Print(vector<int> A) {
    for(int i = 0; i < A.size() - 1; ++i) {
        cout << A[i] << ' ';
    }
    cout << A[A.size()-1] << endl;
}

void InsertSort(vector<int> A) {
    int N = A.size();
    for(int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = v;
        Print(A);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    Print(A);
    InsertSort(A);
    return 0;
}
