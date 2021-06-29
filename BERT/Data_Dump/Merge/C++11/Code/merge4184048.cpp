#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ms(s,x) memset(s,x,sizeof(s))
#define pb push_back
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 5e5+5;
const ll MOD = 1e9+7;

int num[MAXN], tmp[MAXN];
int ans = 0;

void mergesort(int l, int r)
{
    if (r-l > 1)
    {
        int mid = (l+r)>>1;
        int i = l, j = mid, k = l;
        mergesort(l, mid);
        mergesort(mid, r);
        while (i < mid && j < r)
        {
            ans++;
            if (num[i] <= num[j])
                tmp[k++] = num[i++];
            else
                tmp[k++] = num[j++];
        }
        while (i < mid){
            ans++;
            tmp[k++] = num[i++];
        }
        while (j < r){
            ans++;
            tmp[k++] = num[j++];
        }
        rep(h, l, r-1){
            num[h] = tmp[h];
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    rep(i, 0, n-1){
        cin >> num[i];
    }
    mergesort(0, n);
    rep(i, 0, n-1)
    {
        if (i)
            putchar(' ');
        cout << num[i];
    }
    cout << endl << ans << endl;

    return 0;
}

