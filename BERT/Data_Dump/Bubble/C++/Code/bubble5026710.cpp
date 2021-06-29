#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, res = 0;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < n - 1; i++)
    {
        for(ll j = n - 1; j > i; j--)
        {
            if(a[j] < a[j - 1])
            {
                res++;
                swap(a[j], a[j - 1]);
            }
        }
    }
    for(ll i = 0; i < n; i++)
    {
        cout << a[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl << res << endl;
}

