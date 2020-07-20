#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define co(ans) cout<<ans<<endl;
#define COYE cout<<"YES"<<endl;
#define COYe cout<<"Yes"<<endl;
#define COye cout<<"yes"<<endl;
#define CONO cout<<"NO"<<endl;
#define CONo cout<<"No"<<endl;
#define COno cout<<"no"<<endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
#define MAX 510000
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
using namespace std;


int bubbleSort(int A[],int N){
    int sw=0;
    bool flag=1;
    for(int i=0; flag; ++i){
        flag=0;
        for(int j=N-1; j>=i+1; --j){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int A[100],N,sw;
    cin>>N;
    for(int i=0; i<N; ++i) cin>>A[i];
    
    sw=bubbleSort(A,N);
    
    for(int i=0; i<N; ++i){
        if(i) cout<<" ";
        cout<<A[i];
    }
    
    cout<<endl;
    cout<<sw<<endl;
    
    return 0;
}
