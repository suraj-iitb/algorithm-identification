#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define CLR(a) memset((a), 0, sizeof(a))
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

using LL = long long;
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const double EPS = 1e-10;
const double PI = acos(-1.0);

void print(vector<int> v){
    int size = v.size() - 1;
    REP(i, size)
    {
        if (i == v.size())
            cout << v[i];
        else
            cout << v[i] << " ";
    }
    cout << v[size] << endl;

}

void buble_Sort(vector<int> v, int n){
    bool flag = true;
    int count_exchange = 0;
    while(flag){
        flag = false;
        for(int j= n-1; j>=1; j--){
            if(v[j]<v[j-1]){
                count_exchange++;

                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
                flag = true;
            }
        }
    }

    print(v);
    cout << count_exchange << endl;
}

signed main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;
    REP(_, n)
    {
        int num;
        cin >> num;
        v.PB(num);
    }

    buble_Sort(v, n);
}
