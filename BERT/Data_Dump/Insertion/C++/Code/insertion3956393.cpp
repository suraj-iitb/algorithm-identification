#include <bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
using namespace std;


void trace(int A[],int N){
    REP(i,N){
        if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}


int main(){
    int N;
    cin >> N;
    int r[N];
    REP(i,N)cin >> r[i];
    trace(r,N);
    for(int i=1;i<N;i++){
        int value = r[i],j = i-1;
        while(j>=0 && r[j] > value){
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = value;
        trace(r,N);
    }
}

