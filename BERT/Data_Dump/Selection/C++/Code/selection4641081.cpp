#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int cnt = 0;

vector<int> selectionsort(vector<int> &A, int N) {
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        if (A[i] != A[minj])
            swap(A[i], A[minj]), cnt++;
    }

    return A;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    vector<int> sortedA = selectionsort(A, N);
    rep(i, N-1) { cout << sortedA[i] << " "; }
    cout << sortedA[N-1] << endl;
    cout << cnt << endl;
    return 0;
}
