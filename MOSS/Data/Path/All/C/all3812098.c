// 1_warshall_floydlib_a
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

vector<vector<ll>> d;
vector<vector<pair<int, int>>> g;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    d.resize(v, vector<ll> (v));
    g.resize(v);
    rep(i, v){
        rep(j, v){
            d[i][j] = INF;
        }
    }
    rep(i, v) d[i][i] = 0;
    rep(i, e){
        int s ,t, w;
        cin >> s >> t >> w;
        d[s][t] = w;
        g[s].push_back(make_pair(t, w));
    }

    for(int k = 0; k < v; k++){
        rep(i, v){
            rep(j, v){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for(int k = 0; k < v; k++){
        rep(i, v){
            rep(j, v){
                if(d[i][k] == INF || d[k][j] == INF) continue;
                if(d[i][k] + d[k][j] < d[i][j]){
                    cout << "NEGATIVE CYCLE" << endl;
                    exit(0);
                }
            }
        }
    }

    rep(i, v){
        rep(j, v - 1){
            if(d[i][j] == INF) cout << "INF" << " ";
            else cout << d[i][j] << " ";
        }
        int j = v - 1;
        if(d[i][j] == INF) cout << "INF";
        else cout << d[i][j];
        cout << endl;
    }


    return 0;
}

