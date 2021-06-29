#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define REP3(i,x,n) for(int i=x; i>(n); i--)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();


void bubblesort(long long n,long long A[]){
    int flag = 1;
    long long i = 0;
    int count = 0;
    while(flag){
        flag = 0;
        REP3(j,n-1,i){
            if(A[j] < A[j-1]){
                swap(A[j-1],A[j]);
                flag = 1;
                count++;
            } 
        }
        i++;
    }
    REP(k,n-1){printf("%lld ",A[k]);}
    printf("%lld\n",A[n-1]);
    printf("%d\n",count);
}


int main(){
    long long n;
    scanf("%lld",&n);
    long long A[n];
    REP(i,n){scanf("%lld ",&A[i]);}
    bubblesort(n,A);

    return 0;
}
