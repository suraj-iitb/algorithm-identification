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
#include <stdio.h>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long INF = 10000000000;
const int MOD = 1000000007;


int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<P>>G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        P p = P(d, t);
        G.at(s).push_back(p);
    }
    vector<vector<ll>> dp(V, vector<ll>(V,INF));
    for (int i = 0;i < V;i++) {
        dp.at(i).at(i) = 0;
    }
    for (int i = 0;i < V;i++) {
        for (int j = 0;j < G.at(i).size();j++) {
            dp.at(i).at(G.at(i).at(j).second) = G.at(i).at(j).first;
        }
    }
    for (int k = 0;k < V;k++) {
        for (int i = 0;i < V;i++) {
            for (int j = 0;j < V;j++) {
                if ((dp.at(i).at(k) != INF&&dp.at(k).at(j)!=INF)||dp.at(i).at(j)!=INF) {
                    dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
                }
            }
        }
    }
    bool negative = false;
    for (int i = 0;i < V;i++) {
        if (dp.at(i).at(i) < 0) {
            negative = true;
        }
    }
    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i = 0;i < V;i++) {
            for (int j = 0;j < V;j++) {
                if (dp.at(i).at(j) == INF) {
                    cout << "INF";
                }
                else {
                    cout << dp.at(i).at(j);
                }
                if (j == V - 1) {
                    cout << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
	return 0;
}
