#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)
#define repb(bit, n, init) for (ll bit = init; bit < (1 << n); ++bit)

void insertionSort(vector<int> &A)
{
    repi(i, A.size(), 1)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        repi(k, A.size(), 0)
        {
            cout << A[k] << ((k + 1) % A.size() ? " " : "");
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    repi(i, n, 0)
    {
        cin >> A[i];
        cout << A[i] << ((i + 1) %n ? " " : "");
    }
    cout << endl;
    insertionSort(A);
    return 0;
}
