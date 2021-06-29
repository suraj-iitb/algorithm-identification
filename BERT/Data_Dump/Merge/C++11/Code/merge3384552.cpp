#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <random>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);
typedef pair<int, int> P;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
#define OUTPUT(i) (cout << (ll)i << endl)
#define ALL(a) ((a).begin(), (a).end())

bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int n;

int cnt;
void merge(vector<int> &v, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; ++i)
        L[i] = v[left + i];
    for (int i = 0; i < n2; ++i)
    {
        R[i] = v[mid + i];
    }
    L[n1] = (1LL << 31) - 1;
    R[n2] = (1LL << 31) - 1;

    int i = 0, j = 0;
    for (int k = left; k < right; ++k)
    {
        cnt++;
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }
}

void mergesort(vector<int> &v, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergesort(v, left, mid);
        mergesort(v, mid, right);
        merge(v, left, mid, right);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(15);

    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    mergesort(v, 0, n);

    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
