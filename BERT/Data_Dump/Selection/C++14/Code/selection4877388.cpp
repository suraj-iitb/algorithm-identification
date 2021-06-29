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

int InsertSort(vector<int>& A) {
    int cnt = 0;
    int N = A.size();
    rep(i, N) {
        int min_j = i;
        for(int j = i+1; j < N; ++j) {
            if(A[min_j] > A[j]) {
                min_j = j;
            }
        }
        if(i==min_j) continue;
        swap(A[i], A[min_j]);
        ++cnt;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int cnt = InsertSort(A);
    Print(A);
    cout << cnt << endl;
    return 0;
}
