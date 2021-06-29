#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define yes(ans) if(ans)printf("yes\n");else printf("no\n")
#define Yes(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YES(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector1d(type,name,...) vector<type>name(__VA_ARGS__)
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
const int MOD2=998244353;
const int INF=1<<30;
const ll INF2=(ll)1<<60;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T,class L>void scan(pair<T, L>& p){scan(p.first);scan(p.second);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T,class L>void print(const pair<T, L>& p){print(p.first);putchar(' ');print(p.second);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}

//負の閉路がない場合はtrue，負の閉路がある場合はfalseを返す
bool warshallFloyd(vector<vector<ll>> &A){
    int n=A.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(A[i][k]==INF2)continue;
            for(int j=0;j<n;j++){
                if(A[k][j]==INF2)continue;
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(A[i][i]<0)return false;
    }
    return true;
}

int main(){
    INT(n,m);
    vector2d(ll,A,n,n,INF2);
    int to,from,d;
    rep(i,m){
        in(to,from,d);
        A[to][from]=d;
    }
    for(int i=0;i<n;i++)A[i][i]=0;
    if(warshallFloyd(A)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j)cout<<" ";
                if(A[i][j]!=INF2)cout<<A[i][j];
                else cout<<"INF";
            }
            cout<<endl;
        }
    }else{
        cout<<"NEGATIVE CYCLE"<<endl;
    }
}
