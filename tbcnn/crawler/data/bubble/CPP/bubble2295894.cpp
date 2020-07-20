#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;
vll a;
vll b;
lli ans = 0;

void output(){
    cout << a[0];
    for(lli i = 1;i < n;i++){
        cout << " " << a[i];
    }
    cout << endl;
}

int main(){
    cin >> n;
    a = vll(n);
    for(lli i = 0;i < n;i++) cin >> a[i];
    for(lli i = n-1;i >= 0;i--){
        for(lli j = n-1;j > 0;j--){
            if(a[j] < a[j-1]) swap(a[j],a[j-1]),ans++;
        }
    }
    output();
    cout << ans << endl;
    return 0;
}
