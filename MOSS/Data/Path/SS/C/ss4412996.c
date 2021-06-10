#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Graph = vector<vector<T>>;

struct Dest {
    int to;
    int cost;
};

struct Node {
    vector<Dest> dests;
    int distance;
    bool checked;
};

void printFixedDouble(double d, int fix) {
    cout << std::fixed;
    cout << std::setprecision(fix) << d << endl;
}

int main() {
    int nodeNum, linkNum, startIndex;
    cin >> nodeNum >> linkNum >> startIndex;
    vector<Node> nodes;
    rep(i, nodeNum) {
        Node n;
        n.distance = -1;
        n.checked = false;
        nodes.push_back(n);
    }
    rep(i, linkNum) {
        int s, t, d;
        cin >> s >> t >> d;
        nodes[s].dests.push_back({.to = t, .cost = d});
        // nodes[t].dests.push_back({.to = s, .cost = d});
    }

    auto compare = [](Node x, Node y) {
        return x.distance > y.distance;
    };

    std::priority_queue<Node, vector<Node>, decltype(compare)> queue{compare};
    nodes[startIndex].distance = 0;
    queue.push(nodes[startIndex]);

    while (!queue.empty()) {
        Node n = queue.top();
        queue.pop();
        if (n.checked) continue;
        n.checked = true;
        for (auto& next : n.dests) {
            if (nodes[next.to].distance == -1 || nodes[next.to].distance > n.distance + next.cost) {
                nodes[next.to].distance = n.distance + next.cost;
                queue.push(nodes[next.to]);
            }
        }
    }
    for (auto &node : nodes) {
        if (node.distance == -1) {
            cout << "INF" << endl;
        } else {
            cout << node.distance << endl;
        }
        
    }
}
