#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl;
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<int>& a,int n);

int n;


signed main(){
    cin >> n;
    vec(a,n);
    input(a,n);
    bool b = true;
    int ans = 0;
    while(b){
        b = false;
        for(int i = n-1; i>0;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                b = true;
                ans++;
            }
        }
    }
    REP(i,n){
        cout << a[i];
        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
    print(ans);

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<int>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

