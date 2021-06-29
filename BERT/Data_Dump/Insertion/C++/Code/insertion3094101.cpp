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

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i]; //挿入する値
        int j;
        for (j=i-1; j >= 0 && a[j] > tmp; j--)
            a[j + 1] = a[j]; //要素を右にずらす
        a[j+1] = tmp;
        trace(a, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[105];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    trace(a, n);
    insertionSort(a, n);
}
