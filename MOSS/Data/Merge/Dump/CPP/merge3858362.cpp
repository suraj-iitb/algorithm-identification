#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 500000;
int L[MAX / 2 + 2], R[MAX / 2 + 2];
int a[MAX];
int cnt = 0;

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = a[left + i];
    rep(i, n2) R[i] = a[mid + i];
    L[n1] = R[n2] = 1e9 + 1;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        a[k] = (L[i] <= R[j] ? L[i++] : R[j++]);
    }
}

void mergesort(int a[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    mergesort(a, 0, n);
    rep(i, n)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
    OP(cnt);
    return 0;
}
