#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define REP3(i,x,n) for(int i=x; i>(n); i--)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();



void selectionsort(long long N,long long A[]){
    long long minj,count = 0;
    REP(i,N){
        minj = i;
        REP2(j,i,N){
            if(A[j]<A[minj]){
                minj = j;
                
            }
        }
        if(A[i]!=A[minj]){
            swap(A[i],A[minj]);
            count++;
        }
    }
    REP(k,N-1){printf("%lld ",A[k]);}
    printf("%lld\n",A[N-1]);
    printf("%d\n",count);
}


int main(){
    long long n;
    scanf("%lld",&n);
    long long A[n];
    REP(i,n){scanf("%lld ",&A[i]);}
    selectionsort(n,A);

    return 0;
}
