#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>
#include <random>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod  1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

ll V, E;
ll d[105][105];

void init(){
  for(int i = 0; i < 105; i++){
    for(int j = 0; j < 105; j++){
      if(i == j) d[i][j] = 0;
      else d[i][j] = LLONG_MAX / 10;
    }
  }
}

string out(ll n){
  if(n == LLONG_MAX/10)return "INF";
  else return to_string(n);
}

bool is_negative_roop(){
  for(int i = 0; i < V; i++){
    if(d[i][i] < 0) return true;
  }
  return false;
}

int main(){
  init();
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    ll s, g, c;
    cin >> s >> g >> c;
    d[s][g] = min(d[s][g], c);
  }

  for(int k = 0; k < V; k++){
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++){
	if(d[i][k] != LLONG_MAX/10 && d[k][j] != LLONG_MAX/10) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  if(is_negative_roop()){
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }

  for(int i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
      if(j == 0) cout << out(d[i][j]);
      else cout << " " << out(d[i][j]);
    }
    cout << endl;
  }
  return 0;
}

