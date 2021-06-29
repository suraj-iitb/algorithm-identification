#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define LLINF (1e18)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int ans;

void merge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> l(n1 + 1);
    vector<int> r(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = a[mid + i];
    }
    l[n1] = INF;
    r[n2] = INF;
    int i, j;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        ans++;
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &a, int left, int right)
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << a[i];
        }
        else
        {
            cout << a[i] << ' ';
        }
    }
    cout << endl;
    cout << ans << endl;
}
