
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using ll = long long int;
using ul = unsigned long long int;
const ll LL_MAX (1LL<<60);
const ll MOD (1000000007);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];

    ll cnt (0);
    rep(i,0,n-1)
    {
        ll minj = i;
        rep(j,i,n)
        {
            if (a[j] < a[minj])
                minj= j;
        }
        if (i!=minj)
            swap(a[i], a[minj]), cnt++;    
    }

    for (size_t i=0; i<a.size(); i++)
        if (a.size()-1 != i)
            cout << a[i] << ' ';
        else
            cout << a[i];
    cout << endl;

    cout << cnt << endl;

    return 0;
}

