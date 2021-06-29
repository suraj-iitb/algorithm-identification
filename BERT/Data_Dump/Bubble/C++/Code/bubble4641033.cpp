#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int cnt = 0;

vector<int> bubbleSort(vector<int> &A, int N) {
    bool flag = true;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j > 0; j--) {
            if (A[j] < A[j - 1])
                swap(A[j], A[j - 1]), cnt++, flag = true;
        }
    }

    return A;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    vector<int> sortedA = bubbleSort(A, N);
    rep(i, N - 1) { cout << sortedA[i] << " "; }
    cout << sortedA[N - 1] << endl;
    cout << cnt << endl;
}
