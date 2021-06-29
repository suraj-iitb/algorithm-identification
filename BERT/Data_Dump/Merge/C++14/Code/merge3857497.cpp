#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define ALL(a) a.begin(), a.end()
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = 2147483647;
const ll MOD = 1e9 + 7;

int n, cnt = 0;
int S[500000];

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
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

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right) {
        // cnt++;
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, n) { cin >> S[i]; }
    mergeSort(S, 0, n);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << S[i];
    }
    cout << "\n"
         << cnt << endl;
    return 0;
}
