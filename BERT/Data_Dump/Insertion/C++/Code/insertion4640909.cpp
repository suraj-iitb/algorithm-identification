#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    rep(i, N - 1) { cout << A[i] << " "; }
    cout << A[N - 1] << endl;
    for (int i = 1; i <= N - 1; i++) {
        int v = A[i], j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        rep(i, N - 1) { cout << A[i] << " "; }
        cout << A[N - 1] << endl;
    }
}
