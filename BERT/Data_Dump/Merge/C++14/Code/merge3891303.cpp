#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1e18;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int N;
ll A[500100];
const ll SENTINEL = numeric_limits<ll>::max();
int cnt = 0;

void merge(ll A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    ll L[n1+1], R[n2+1];
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i = 0, j = 0;
    for(int k=left; k<right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void merge_sort(ll A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void print_array(ll A[]) {
    rep(i, N) {
        cout << A[i];
        if (i != N-1) cout << " ";
    }
    cout << endl;
}

int main() {
    cin >> N;
    rep(i, N) cin >> A[i];
    merge_sort(A, 0, N);
    print_array(A);
    cout << cnt << endl;
}

