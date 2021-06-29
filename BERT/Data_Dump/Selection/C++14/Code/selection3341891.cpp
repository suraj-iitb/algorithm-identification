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

void selection(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minj])
                minj = j;
        }
        if (a[i] != a[minj])
        {
            swap(a[i], a[minj]);
            res++;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    selection(a, n);
    printv(a);
    cout << res << endl;
}

