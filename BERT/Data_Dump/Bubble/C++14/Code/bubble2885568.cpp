#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
using namespace std;
using pii = pair<int,int>;

int bubbleSort(int a[], int N)
{
    bool swaped=true;
    int cnt = 0;
    for (int i=0; swaped; ++i) {
        swaped = false;
        for (int j=N-1; j > i; --j) {
            if (a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                swaped = true;
                ++cnt;
            }
        }
    }
    return cnt;
}

signed main()
{
   cin.tie(0), ios::sync_with_stdio(false);
   int N, a[102];
   cin >> N;

   rep(i, N) cin >> a[i];

   int swapCnt = bubbleSort(a, N);

   rep(i, N) {
       cout << a[i] << (i+1 < N ? ' ' : '\n');
   }
   outl(swapCnt);
}


