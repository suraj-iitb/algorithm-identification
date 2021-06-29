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

void trace(int A[],int N){
    int i;
    for(int i=0; i<N; ++i){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertionSort(int A[],int N){
    int j,i,v;
    for(int i=1; i<N; ++i){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        trace(A,N);
    }
}

int main(){
    int N,i,j;
    int A[100];
    
    scanf("%d",&N);
    for(int i=0; i<N; ++i) scanf("%d",&A[i]);
    
    trace(A,N);
    insertionSort(A,N);
    
    return 0;
}
