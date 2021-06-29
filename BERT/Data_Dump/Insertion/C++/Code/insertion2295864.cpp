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
    for(lli i = 0;i < n;i++){
        for(lli j = i-1;j >= 0 && a[j] > a[j+1];j--){
            swap(a[j],a[j+1]);
        }
        output();
    }
    return 0;
}
