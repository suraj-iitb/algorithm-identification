#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

using namespace std;
using ll = long long;

template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }

    REP(j, N)
    {
        cout << (j ? " " : "") << A[j];
    }
    cout << "\n";

    FOR(i, 1, N)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 and A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        REP(j, N)
        {
            cout << (j ? " " : "") << A[j];
        }
        cout << "\n";
    }

    return 0;
}
