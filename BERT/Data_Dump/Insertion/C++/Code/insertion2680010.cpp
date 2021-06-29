#include<bits/stdc++.h>
#define REP(i,n) for(long long i=0;i<n;++i)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    REP(i,n) scanf("%d",&A[i]);
    int v,j;
    REP(i,n){
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    puts("");
    FOR(i,1,n){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
        REP(k,n){
            if(k) printf(" ");
            printf("%d",A[k]);
        }
        puts("");
    }
    return 0;
}


