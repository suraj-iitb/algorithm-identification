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

const int INF = 1000000000;
const int MOD = 1000000007;


int main() {
    int V, E, R;
    cin >> V >> E >> R;
    vector<vector<P>>G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        P p = P(d, t);
        G.at(s).push_back(p);
    }
    vector<int>dist(V,INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, R));
    while (pq.size()) {
        P A = pq.top();
        pq.pop();
        if (A.first > dist.at(A.second)) {
            continue;
        }
        dist.at(A.second) = A.first;
        for (int i = 0;i < G.at(A.second).size();i++) {
            P B = P(G.at(A.second).at(i).first + dist.at(A.second), G.at(A.second).at(i).second);
            if (B.first > dist.at(B.second)) {
                continue;
            }
            dist.at(B.second) = B.first;
            pq.push(B);
        }
    }
    for (int i = 0;i < V;i++) {
        if (dist.at(i) == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist.at(i) << endl;
        }
    }
	return 0;
}
