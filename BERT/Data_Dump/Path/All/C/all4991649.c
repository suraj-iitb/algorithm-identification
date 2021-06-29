#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define all(a) (a).begin(),(a).end()
#define mpa make_pair
#define fi first
#define se second
#define emb emplace_back
using namespace std;
//using namespace atcoder;
typedef long long ll;
const ll inf = 100100100100100100;
template <class T> void input(vector<T> &v){
  for(int i=0;i<v.size();i++) cin >> v[i];
}
template <class T> void output(vector<T> &v,bool space = false){
  if(space){
    for(int i=0;i<v.size()-1;i++) cout << v[i] << ' ';
    cout << v.back() << '\n';
  }
  else{
    for(int i=0;i<v.size();i++) cout << v[i] << '\n';
  }
}
template <class T> T gcd(T x,T y){
  if(x%y == 0) return y;
  else return gcd(y,x%y);
}
template <class T> T lcm(T x,T y){
  return x/gcd(x,y)*y;
}
template <class T> bool isprime(T N){
  if(N <= 1) return false;
  for(T i=2;i*i<=N;i++){
    if(N%i == 0) return false;
  }
  return true;
}
vector<bool> isprime_format(int N){
  vector<bool> ans(N+1,1);
  ans[0] = ans[1] = false;
  for(int i=2;i<=N;i++){
    if(!ans[i]) continue;
    for(int j=i+i;j<=N;j+=i) ans[j] = false;
  }
  return ans;
}
vector<int> prime_format(int N){
  vector<bool> ans = isprime_format(N);
  vector<int> ans2;
  for(int i=2;i<=N;i++){
    if(ans[i]) ans2.emplace_back(i);
  }
  return ans2;
}
template <class T> class WarshallFloyd{
  T N,inf;
  vector<vector<T>> D;
  bool isdirect;
  void setting(){
    for(T k=0;k<N;k++){
      for(T i=0;i<N;i++){
        for(T j=0;j<N;j++){
          if(D[i][k] == inf || D[k][j] == inf) continue;
          D[i][j] = min(D[i][j],D[i][k]+D[k][j]); 
        }
      }
    }
  }
public:
  WarshallFloyd(T N,vector<T> &u,vector<T> &v,vector<T> &c,T inf,bool isdirect){
    this->N = N;
    this->inf = inf;
    this->isdirect = isdirect;
    assert(u.size() == v.size());
    vector<vector<T>>(N,vector<T>(N,inf)).swap(D);
    for(T i=0;i<N;i++) D[i][i] = 0;
    for(T i=0;i<u.size();i++){
      D[u[i]][v[i]] = min(D[u[i]][v[i]],c[i]);
      if(!isdirect) D[v[i]][u[i]] = min(D[v[i]][u[i]],c[i]);
    }
    setting();
  }
  WarshallFloyd(vector<vector<T>> D,T inf,bool isdirect){
    this->N = D.size();
    this->inf = inf;
    this->D = D;
    this->isdirect = isdirect;
    setting();
  }
  void append(T s,T t,T c){
    for(T i=0;i<N;i++){
      for(T j=0;j<N;j++){
        if(D[i][s] != inf && D[t][c] != inf){
          D[i][j] = min(D[i][j],D[i][s]+c+D[t][j]);
        }
        if(!isdirect && D[i][t] != inf && D[s][j] != inf){
          D[i][j] = min(D[i][j],D[i][t]+c+D[s][j]);
        }
      }
    }
  }
  T at(T i,T j){
    return D[i][j];
  }
  bool negative_cycle(){
    for(T i=0;i<N;i++){
      if(D[i][i] < 0) return true;
    }
    return false;
  }
  vector<vector<T>> Graph(){
    return D;
  }
};
int main(){
  cin.tie(nullptr);ios::sync_with_stdio(false);
  ll N,M,i,j;cin >> N >> M;
  vector<ll> S(M),T(M),D(M);
  for(i=0;i<M;i++) cin >> S[i] >> T[i] >> D[i];
  WarshallFloyd<ll> W(N,S,T,D,inf,true);
  if(W.negative_cycle()){
    cout << "NEGATIVE CYCLE\n";return 0;
  }
  vector<vector<ll>> G = W.Graph();
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(G[i][j] == inf) cout << "INF";
      else cout << G[i][j];
      if(j+1<N) cout << " ";
    }
    cout << "\n";
  }
}
