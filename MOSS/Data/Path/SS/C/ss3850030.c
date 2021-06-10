#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int Inf = 10000*100000+100;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    priority_queue<int> x;
    vector<int> s; 
    vector<int> t;
    vector<int> d;
    for(int i = 0; i < e; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        s.push_back(start);
        t.push_back(end);
        d.push_back(cost);
    }

    vector<int> ans(v, Inf);
    ans[r] = 0;
    for(int i = 0; i < v; i++){
        bool update = false;
        for(int j = 0; j < e; j++){
            if(ans[s[j]]<Inf && ans[s[j]]+d[j]<ans[t[j]]){
                ans[t[j]] = ans[s[j]]+d[j];
                update = true;
            }
        }
        if(!update){
            break;
        }
    }
    for(int i = 0; i < v; i++){
        if(ans[i] != Inf){
            cout << ans[i] << endl;
        }
        else {
            cout << "INF" << endl;
        }
    }
}
