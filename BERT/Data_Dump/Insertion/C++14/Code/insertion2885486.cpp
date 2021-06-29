#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
using namespace std;
using pii = pair<int,int>;

void print(int a[], int n)
{
    rep(i, n) {
        printf("%d%c", a[i], i+1 < n ? ' ' : '\n');
    }
}

signed main()
{
    int N, a[101];
    scanf("%d", &N);

    rep(i, N) scanf("%d", a+i);
    print(a, N);

    for (int i=1; i<N; ++i) {
        int j = i-1;
        int tmp = a[i];
        while (j >= 0 && a[j] > tmp) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = tmp;
        print(a, N);
    }
}


