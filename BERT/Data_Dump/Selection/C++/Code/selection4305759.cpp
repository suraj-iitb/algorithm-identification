#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

//選択ソート（０オリジン）
int selectionSort(int A[], int N){
    int i,j,sw = 0,minj;
    for(i=0; i<N-1; i++){
        minj=i;
        for(j=i; j<N; j++){
            if(A[j] < A[minj]) minj=j;
        }
        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    return sw;
}

int main() {
    int A[100], N, i, sw;

    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    sw = selectionSort(A, N);

    for(i=0; i<N; i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n",sw);

    return 0;

}
