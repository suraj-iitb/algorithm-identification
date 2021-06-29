#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
void insertionSort(vector<int> &a, int n)
{
    rep(k, n)
    {
        cout << a[k] << (k != n - 1 ? " " : "");
    }
    cout << endl;

    rep(i, 1, n)
    {
        //cerr << i << "," << a[i] << endl;
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        rep(k, n)
        {
            cout << a[k] << (k != n - 1 ? " " : "");
        }
        cout << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    vector<int> v(n, 0);
    rep(i, n)
    {
        cin >> v[i];
    }
    insertionSort(v, n);

    return 0;
}

