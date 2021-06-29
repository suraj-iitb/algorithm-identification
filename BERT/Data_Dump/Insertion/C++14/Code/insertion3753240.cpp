#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = 1e14;
const ll MOD = 1e9 + 7;
void insertionSort(vector<int> array, int n)
{
    for (int i = 1; i < n; i++) {
        int cur = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > cur) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = cur;
        rep(k, n)
        {
            cout << array[k];
            if (k != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    rep(k, n)
    {
        cout << a[k];
        if (k != n - 1)
            cout << " ";
    }
    cout << endl;

    insertionSort(a, n);
    return 0;
}
