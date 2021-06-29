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
const int MAXN = 1e5+5;
const ll MOD = 1e9+7;

int box[MAXN];

int main()
{
    IOS;
    ms(box, 0);
    const int MIN = 0, MAX = 1e4;
    int n, num;
    cin >> n;
    rep(i, 1, n){
        cin >> num;
        box[num]++;
    }
    int t = 0;
    rep(i, MIN, MAX){
        rep(j, 1, box[i]){
            if (t++)
                cout << ' ';
            cout << i;
        }
    }
    cout << endl;

    return 0;
}

