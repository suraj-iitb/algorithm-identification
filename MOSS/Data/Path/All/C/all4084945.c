//  Created by conan1024hao in 2019.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define INF 10e16
#define MOD 1000000007
#define  mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//--------------------------------------------------------------------------
ll c[110][110];
int n;
void warshall_floyd(){
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
        if(c[i][k]==INF)continue;
      for (int j = 0; j < n; j++) {  // 終点
          if(c[k][j]==INF)continue;
        chmin(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
}

//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int m;cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                c[i][j]=0;
            else
                c[i][j]=INF;
        }
            
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ll cd;
        cin>>cd;
        c[a][b]=cd;
        
    }
    warshall_floyd();
    for(int i=0;i<n;i++){
        if(c[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j]!=INF)
                cout<<c[i][j];
            else
                cout<<"INF";
            if(j<n-1)cout<<" ";
        }
        cout<<endl;
    }
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------





