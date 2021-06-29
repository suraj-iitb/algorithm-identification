
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef long long ll;
const ll LL_MAX (1LL<<60);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

ll bubble_sort(vector<ll> *a)
{
    bool is_sorted(false);
    const ll n (a->size());
    ll cnt(0);

    //cout << n << endl;

    while (!is_sorted)
    {
        is_sorted = true;
        for (ll i=n-1; i>=1; i--)
            if (a->at(i) < a->at(i-1))
                swap(a->at(i), a->at(i-1)), is_sorted = false, cnt++;
    }

    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >>n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];

    //for (auto i: a)
    //    cout << i << endl;

    ll cnt = bubble_sort(&a);

    rep(i,0,n) 
    {
        if (i != n-1)
            cout << a[i] << ' ';
        else
            cout << a[i] << endl;
    } 
    
    cout << cnt << endl;

    return 0;
}

