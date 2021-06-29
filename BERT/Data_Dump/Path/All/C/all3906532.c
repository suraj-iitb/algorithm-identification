#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
using ll=long long;
using namespace std;
//const int INF = 7+(1e+9);
ll GCD(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return GCD(y, x % y);
    }
}
ll LCM(ll x, ll y)
{
    return x / GCD(x, y) * y;
}
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
vector<vector<char>> vec(12,vector<char>(12));

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int dfs(int y,int x){
    vec[y][x]='5';
    for(int i=0;i<4;i++){
        if(x+dx[i]<12&&x+dx[i]>=0&&y+dy[i]<12&&y+dy[i]>=0&&vec[dy[i]+y][dx[i]+x]=='1'){
            dfs(y+dy[i],x+dx[i]);
        }
    }
    return 0;
}
int main(){
   ll v,e;cin>>v>>e;
   vector<vector<ll>> vec(v,vector<ll>(v,1e15));
   for(int i=0;i<e;i++){
       ll x,y,w;
       cin>>x>>y>>w;
       vec[x][y]=w;
   }
   for(int k=0;k<v;k++){
       for(int i=0;i<v;i++){
           for(int j=0;j<v;j++){
               if(vec[i][k]!=1e15&&vec[k][j]!=1e15){
                   vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
               }
           }
       }
    }
    for(int i=0;i<v;i++){
       if(vec[i][i]<0){
           cout<<"NEGATIVE CYCLE"<<endl;
           return 0;
       }
   }
   for(int i=0;i<v;i++){
       for(int j=0;j<v;j++){
           if(i==j){
               cout<<0;
               if(j!=v-1)cout<<" ";
               continue;
           }
           if(vec[i][j]==1e15){
               cout<<"INF";
           }else{
               cout<<vec[i][j]; 
           }
           if(j!=v-1)cout<<" ";
       }
       cout<<endl;
   }
}

