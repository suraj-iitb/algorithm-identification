#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
using namespace std;
using pii = pair<int,int>;

int selectionSort(int a[], int n)
{
    int cnt = 0;
    rep(i, n-1) {
        int *minpos = min_element(a+i, a+n);
        if (a+i != minpos) {
            ++cnt;
            swap(a[i], *minpos);
        }
    }
    return cnt;
}

signed main()
{
   cin.tie(0), ios::sync_with_stdio(false);

   int n;
   int a[102];
   cin >> n;
   rep(i, n) cin>>a[i];
   int cnt = selectionSort(a, n);

   rep(i, n) cout << a[i] << (i+1 < n ? ' ' :'\n');
   outl(cnt);
}


