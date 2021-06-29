#define _USE_MATH_DEFINES
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>

/*
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
*/

using namespace std;

int bubbleSort(int a[], int n)
{
    int ans = 0;
    int tmp = a[n];
    bool flg = true;

    for (int i = 0; flg; i++)
    {
        flg = false;
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j], a[j - 1]);
                ans++;
                flg = true;
            }
        }
    }

    for (int i = 0; i < n;i++){
        if(i)
            cout << " ";
        cout << a[i];
    }
    cout << endl;

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int a[105];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << bubbleSort(a, n) << endl;
}
