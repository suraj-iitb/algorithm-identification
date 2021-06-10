#include <iostream>
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int n,m,r,ch[100000],a,b,c;
map<int,int>mp[100000];
vector<P> v[100000];
priority_queue<P,vector<P>,greater<P>> pque;
int main(void){
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        //v[b].push_back({a,c});
    }
    pque.push({1,r});
    while(pque.size()){
        P p=pque.top();
        pque.pop();
        if(ch[p.S]!=0)continue;
        ch[p.S]=p.F;
        for(P x:v[p.S]){
            if(ch[x.F]==0){
                pque.push({p.F+x.S,x.F});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ch[i]==0)cout<<"INF"<<endl;
        else{
            cout<<ch[i]-ch[r]<<endl;
        }
    }
}

