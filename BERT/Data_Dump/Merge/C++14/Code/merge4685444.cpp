#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int cnt = 0;

void MergeSort(vector<int> &A, int left, int right) {
    if (right - left == 1)
        return;
    int mid = (right + left) / 2;

    MergeSort(A, left, mid);
    MergeSort(A, mid, right);

    vector<int> buf;
    for (int i = left; i < mid; i++) {
        buf.push_back(A[i]);
    }

    // 逆順でコピー
    for (int i = right - 1; i >= mid; i--) {
        buf.push_back(A[i]);
    }

    //統合
    int itrl = 0;
    int itrr = buf.size() - 1;
    for (int i = left; i < right; i++) {
        if (buf[itrl] <= buf[itrr]) {
            A[i] = buf[itrl];
            itrl++;
        } else {
            A[i] = buf[itrr];
            itrr--;
        }
        cnt++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    MergeSort(A, 0, N);
    rep(i, N - 1) { cout << A[i] << " "; }
    cout << A[N - 1] << endl;
    cout << cnt << endl;
}
