#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define FAST() cin.tie(0), ios::sync_with_stdio(false)

void print(int *a, int n)
{
    rep(i, n-1)cout << a[i] << ' ';
    cout << a[n-1] << '\n';
}

void insertion_sort(int *a, int n)
{
    print(a, n);
    for(int i=1; i<n; i++){
        const int v = a[i];
        int j;
        for(j=i-1; j>=0 && a[j]>v; --j)
            a[j+1] = a[j];
        a[j+1] = v;
        print(a, n);
    }
}

int main()
{
    FAST();
    int N, a[101];

    cin >> N;
    rep(i, N)cin >> a[i];
    insertion_sort(a, N);
}
