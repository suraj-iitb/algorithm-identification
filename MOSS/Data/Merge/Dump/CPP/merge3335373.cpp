#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <complex>
#include <vector>
#include <algorithm>

#define INF (1<<30)
#define re(i, n) for(int i=0;i<(n);i++)
#define rep(i, s, n) for(int i=(s);i<(n);i++)
#define pe(x) return cout<<(x)<<endl,0
#define PI 3.1415926535897932
using namespace std;
typedef long long ll;

int n;
int *a;
int X = 0;

int merge(int s, int m, int t) {
    int n1 = m - s;
    int n2 = t - m;
    int l[n1], r[n2];
    re(i, n1) l[i] = a[s + i];
    re(i, n2) r[i] = a[m + i];
    int i = 0, j = 0;
    int k = s;
    while (i < n1 || j < n2) {
        if (i < n1) {
            if (j < n2) {
                if (l[i] > r[j])a[k++] = r[j++], X++;
                else a[k++] = l[i++], X++;
            } else a[k++] = l[i++], X++;
        } else {
            if (j < n2) a[k++] = r[j++], X++;
            else { cout << "ERROR" << endl; }
        }
    }
}

void mergesort(int s, int t) {
    if (t - s > 1) {
        int mid = (s + t) / 2;
        mergesort(s, mid);
        mergesort(mid, t);
        merge(s, mid, t);
    }

}

int main(void) {
    cin >> n;
    a = new int[n];
    re(i, n)cin >> a[i];
    mergesort(0, n);
    re(i, n) {
        if (i != 0)cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << X << endl;

}

