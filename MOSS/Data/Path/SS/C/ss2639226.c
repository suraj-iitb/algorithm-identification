#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define INF 1001001001

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    vector<pair<int,int>> adj[100001];
    int V,E,r;
    int dst[100001];
    pair<int,int> d;
    Fill(dst,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

    cin>>V>>E>>r;

    dst[r]=0;

    int s,t,w;

    //??£??\??????????????????
    for(int i=0;i<E;++i){
        cin>>s>>t>>w;
        adj[s].push_back(make_pair(t,w));
    }

    
    for(int i=0;i<adj[r].size();++i){
        Q.push(adj[r][i]);
    }

    while(!Q.empty()){
        d=Q.top(); //?????¢????°??????????
        Q.pop();
        //cerr<<"min is "<<d.first<<" "<<d.second<<"\n";
        if(dst[d.first]>d.second){
            dst[d.first]=d.second;
        }
        
        for(int i=0;i<adj[d.first].size();++i){
            if(dst[adj[d.first][i].first]>d.second+adj[d.first][i].second){
                //cerr<<"new element\n";
                dst[adj[d.first][i].first]=d.second+adj[d.first][i].second;
                pair<int,int> next=make_pair(adj[d.first][i].first,dst[adj[d.first][i].first]);
                Q.push(next);
            }
        }
    }

    for(int i=0;i<V;++i){
        if(dst[i]!=INF){
            cout<<dst[i]<<"\n";
        }
        else{
            cout<<"INF\n";
        }
    }

}
