#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

const ll INF = 10010010010;

int main(){
    int v,e,r;
    cin >> v >> e >> r;
    vector<vector<ll>> to(v);
    vector<vector<ll>> weight(v);
    vector<ll> distance(v);
    //vector<int> visited(v);
    rep(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        to[s].push_back(t);
        weight[s].push_back(d);

        //無向グラフ
        //to[t].push_back(s);
        //weight[t].push_back(d);

    }
    rep(i,v){
        distance[i]=INF;
        //visited[i]=0;
    }
    
    priority_queue<P,
    vector<P>,
    greater<P>
    > Q;
    P p(0,r);
    Q.push(p);
    //visited[r]=1;
    distance[r]=0;

    //int count = 0;
    while(!Q.empty()){
        P now;
        now = Q.top();
        Q.pop();
        if(now.first>distance[now.second]) continue;
        //cout << "now: " << now.first << " "<< now.second << endl;
        rep(i,to[now.second].size()){
            P temp;
            temp.second = to[now.second][i];
            temp.first = now.first+weight[now.second][i];
            
            //cout << "to: " << temp.second <<" " <<temp.first << endl;
            //count++;
            if(temp.first<distance[temp.second]){
                Q.push(temp);
                distance[temp.second]=temp.first;
                //visited[temp.second]=1;
            }
        }

        /*        
        cout << "temp"<<endl;
        rep(j,v){
        cout << j << " " << distance[j] << endl;
        }
        */

    }

    //cout << "ans" << endl;
        rep(i,v){
        if(distance[i]<INF) cout << distance[i] << endl;
        else cout << "INF" << endl;
    }
    //cout << "count: " << count << endl;



}
