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

int selectionSort(int A[],int N){
    int i,j,t,sw=0,minj;
    for(int i=0; i<N-1; ++i){
        minj=i;
        for(int j=i; j<N; ++j){
            if(A[j]<A[minj]) minj=j;
        }
        t=A[i];
        A[i]=A[minj];
        A[minj]=t;
        if(i!=minj) sw++;
    }
    return sw;
}

int main(){
    int A[100],N,i,sw;
    
    scanf("%d",&N);
    for(int i=0; i<N; ++i) scanf("%d",&A[i]);
    
    sw=selectionSort(A,N);
    
    for(int i=0; i<N; ++i){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
    
    return 0;
}
