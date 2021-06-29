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

int BubbleSort(vector<int>& A) {
    int cnt = 0;
    int N = A.size();
    bool flag = true;
    while(flag) {
        flag = false;
        for(int j = N-1; j >= 1; --j) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                ++cnt;
                flag = true;
            }
        }
    }
    return cnt;
}


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int cnt = BubbleSort(A);
    Print(A);
    cout << cnt << endl;
    return 0;
}
