#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

// using int64 = long long;
typedef long long int64;

int64 gcd(int64 a, int64 b) { return b? gcd(b,a%b):a; };
int64 lcm(int64 a, int64 b) { return a/gcd(a,b)*b; };

void print(const vector<int>& a) {
    int n = a.size();
    for (int i=0; i<n; i++) 
        cout << a[i] << (i!=n-1? " " : "\n");
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    print(a);

    for (int i=1; i<n; i++) {
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a);
    }
}

