#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define ALL(a) a.begin(), a.end()
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = 1e14;
const ll MOD = 1e9 + 7;

vector<int>A, B;

void CountingSort(vector<int>& A, vector<int>& B, int k)
{
    vector<int> C(k+1);

    for (auto a: A) {
        C[a]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    A.resize(n), B.resize(n);
    int k = 0;
    rep(i, n)
    { 
        cin >> A[i]; 
        k = max(A[i], k);
    }
    CountingSort(A, B, k);
    rep(i, n)
    {
        if (i != 0) {
            cout << " ";
        }
        cout << B[i];
    }
    cout << endl;
    return 0;
}
