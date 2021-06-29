#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int res = 0;

void merge(vector<ll> &a, int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    vector<ll> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[mid + i];
    }
    L[n1] = 1e15;
    R[n2] = 1e15;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        res++;
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<ll> &a, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n);
    printv(a);
    cout << res << endl;
}
