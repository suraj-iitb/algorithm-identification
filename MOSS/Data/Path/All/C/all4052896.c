#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const long long INF =  99999999999;

long long  d[110][110],V,E;

int main(){
  cin>>V>>E;
  REP(i,V+1)REP(j,V+1)d[i][j]=INF;
  REP(i,V)d[i][i]=0;
  REP(i,E){
    int s,t,cost;
    cin>>s>>t>>cost;
    d[s][t]=cost;
  }
  REP(k,V){
    REP(i,V){
      REP(j,V){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  bool cycle=false;
  REP(i,V)if(d[i][i]<0)cycle=true;
  if(cycle)cout<<"NEGATIVE CYCLE"<<endl;
  else {
    REP(i,V){
      if(d[i][0] >INF/2)cout<<"INF";
      else cout<<d[i][0];
      FOR(j,1,V){
        if(d[i][j]>INF/2)cout<<" "<<"INF";
        else cout<<" "<<d[i][j];
      }
      cout<<endl;
    }
  }
}

