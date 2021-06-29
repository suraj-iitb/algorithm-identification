#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int Mergesort(int *v, int left, int right)
{
    if(right - left <= 1) return 0;
    int res = 0, n = right - left - 1;
    int mid = (left + right) / 2;
    res += Mergesort(v, left, mid);
    res += Mergesort(v, mid, right);
    int buf[n];
    int idx = 0;
    for(int i = left; i < mid; i++) { buf[idx] = v[i], idx++; }
    for(int i = right - 1; i >= mid; i--) { buf[idx] = v[i], idx++; }
    int posL = 0, posR = n;
    for(int i = left; i < right; i++)
    {
        if(buf[posL] <= buf[posR]) { v[i] = buf[posL++]; }
        else { v[i] = buf[posR--]; }
    }
    return res + right - left;
} 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[n + 1];
    for(int i = 0; i < n; i++) cin >> A[i];
    int res = Mergesort(A, 0, n);
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << "\n" << res << "\n";
    return 0;
}


