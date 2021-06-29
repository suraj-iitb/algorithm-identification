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

void trace(int a[], int n)
{
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int selectionSort(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[minj])
                minj = j;
        swap(a[i], a[minj]);
        if (i != minj)
            ans++;
    }
    trace(a, n);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int a[105];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << selectionSort(a, n) << endl;
}
