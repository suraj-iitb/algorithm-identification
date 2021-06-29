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
#include <climits>

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

bool isPrime(int n) {
    if (n != 2 && n % 2 == 0) return false;
    for (int i=3; i*i<=n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ans = 0;
    while(1) {
        bool f = true;
        for (int i=0; i<n-1; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                ans++;
                f = false;
            }
        }
        if (f) break;
    }


    print(a);
    cout << ans << endl;
}

