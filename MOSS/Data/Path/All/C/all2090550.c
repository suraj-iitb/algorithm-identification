#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define FOR(i,a,b) for(int (i)=(a);(i)<int(b);(i)++)
using namespace std;

const int MAX_V = 100; // ????????°????????§???
const int INF = INT_MAX;

int v; // ????????°
int g[MAX_V][MAX_V]; // ??£??\??????
int d[MAX_V][MAX_V]; // ????????????

bool warshallfloyd()
{
  copy(g[0],g[MAX_V],d[0]);
  FOR(i,0,v) d[i][i] = 0;

  FOR(k,0,v){
    FOR(i,0,v){
      FOR(j,0,v){
        if(d[i][k] != INF && d[k][j] != INF)
          d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }

  // ?????????????????????
  FOR(i,0,v) if(d[i][i] < 0) return false;

  return true; // ????????????????????¨?????????
}

int main()
{
  int gv, ge; // gv???????????°???ge???????????°
  cin >> gv >> ge;
  v = gv;
  fill(g[0],g[MAX_V],INF);
  FOR(i,0,ge){
    int gs, gt, gd;
    cin >> gs >> gt >> gd; // ge??????????§???????gt??????????????????gd???????????????
    g[gs][gt] = gd;
  }

  if(warshallfloyd()) // ???????????????????????´???
    FOR(i,0,v){
      FOR(j,0,v){
        if(d[i][j] != INF)
          cout << d[i][j];
        else // ??????j?????????????????´???
          cout << "INF";
        if(j != v-1)
          cout << " ";
        else
          cout << endl;
      }
    }
  else
    cout << "NEGATIVE CYCLE" << endl;
}
