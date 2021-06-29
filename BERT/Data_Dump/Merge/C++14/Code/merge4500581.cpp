#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int a[500500], cnt = 0;

void merge (int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    rep (i, 0, n1) L[i] = a[left + i];
    rep (i, 0, n2) R[i] = a[mid + i];
    L[n1] = inf, R[n2] = inf;

    int i = 0, j = 0;
    rep (k, left, right) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void mergesort (int left, int right) {
    if (right - left > 1) {
        int mid = (left + right) / 2;
        mergesort (left, mid);
        mergesort (mid, right);
        merge (left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    rep (i, 0, n) cin >> a[i];
    mergesort (0, n);
    rep (i, 0, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << cnt << "\n";
}
