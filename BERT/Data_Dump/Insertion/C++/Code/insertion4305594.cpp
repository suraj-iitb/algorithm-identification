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

//配列の要素を順番に出力
void trace(int A[], int N){
    int i;
    for(i=0; i<N; i++){
        if(i>0) printf(" "); //隣接する要素の間に1つの空白を出力
        printf("%d", A[i]);
    }
    printf("\n");
}

//挿入ソート（０オリジン配列）
void insertionSort(int A[], int N){
    int j,i,v;
    for(i=1; i<N; i++){
        v = A[i];
        j = i-1;
        while( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, N);
    }
}

int main() {
    int N, i, j;
    int A[100];

    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);

    trace(A, N);
    insertionSort(A, N);

    return 0;

}
