#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
typedef pair<int, int> P;

ll V, E;
struct edge {
    ll from, to, cost;
};

//vector<vector<edge> > es(10000);
vector<edge> es(10000);
vector<ll> d(101, INF);
vector<ll> reset_d(101, INF);


void shortest_path(ll s) {
    d = reset_d;
    d.at(s) = 0;
    while(true) {
        bool update = 0;
        for(ll i = 0; i < E; i++) {
            edge e = es.at(i);
            if(d.at(e.from) != INF && d.at(e.to) > d.at(e.from) + e.cost) {
                d.at(e.to) = d.at(e.from) + e.cost;
                update = 1;
            }

        }
        if(!update) {
            break;
        }
    }

}

bool find_negative_loop() {
    vector<ll> d(101, 0);

    for(ll i = 0; i < V; i++) {
        for(ll j = 0; j < E; j++) {
            edge e = es.at(j);
            if(d.at(e.to) > d.at(e.from) + e.cost) {
                d.at(e.to) = d.at(e.from) + e.cost;
                if(i == V - 1) {
                    return 1;
                }
            }

        }
    }

    return 0;
}


int main() {
    cin >> V >> E;
    for(ll i = 0; i < E; i++) {
        edge e;
        ll s, t, d;
        cin >> s >> t >> d;
        e.from = s;
        e.to = t;
        e.cost = d;
        es.at(i) = e;
    }

    if(find_negative_loop()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    } else {
        for(ll i = 0; i < V; i++) {
            shortest_path(i);
            for(ll j = 0; j < V; j++) {
                if(j != 0) {
                    cout << ' ';
                }
                if(d.at(j) == INF) {
                    cout << "INF";
                    continue;
                }
                cout << d.at(j);
            }
            cout << endl;
        }
    }

    return 0;
}
/* #include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
typedef pair<int, int> P;

struct edge { int from, to, cost;};


vector<edge> esuse(2000000);
vector<edge> es(2000000);
vector<int> d(100000001, INF);
vector<int> dINF(100000001, INF);
vector<int> dzero(100000001, 0);
int V, E;

bool find_negative_loop() {
    esuse = es;
    d = dzero;

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < E; j++) {
            edge e = esuse.at(j);
            if(d.at(e.from) != INF && d.at(e.to) > d.at(e.from) + e.cost) {
                d.at(e.to) = d.at(e.from) + e.cost;
                if(i == V - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;

}


bool shortest_path(int s) {
    esuse = es;
    d = dINF;
    d.at(s) = 0;
    int ans = 0;

    while(true) {
        ans++;
        bool update = 0;
        for(int i = 0; i < E; i++) {
            edge e = esuse.at(i);
            if(d.at(e.from) != INF && d.at(e.to) > d.at(e.from) + e.cost) {
                d.at(e.to) = d.at(e.from) + e.cost;
                update = true;
            }
        }
        if(!update) {
            break;
        }
        if(ans == V - 1) {
            return 1;
        }
    }

    return 0;
}


int main() {
    int r;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edge e;
        e.from = s;
        e.to = t;
        e.cost = d;
        es.at(i) = e;
    }
    if(shortest_path(r)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    } else {

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(j != 0) {
                    cout << ' ';
                }
                if(d.at(i) == INF) {
                    cout << "INF";
                    continue;
                }
                cout << d.at(i);
            }
            cout << endl;
        }
        */
        /* 
        for(int i = 0; i < V; i++) {
            if(d.at(i) == INF) {
                cout << "INF" << endl;
            } else {
                cout << d.at(i) << endl;
            }
        } 
        */
       
       /*
    }
    return 0;

    //shortest_path(r);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(j != 0) {
                cout << ' ';
            }
            if(d.at(i) == INF) {
                cout << "INF";
                continue;
            }
            cout << d.at(i);
        }
        cout << endl;
    }
    
    return 0;
} */
