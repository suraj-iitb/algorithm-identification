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

//flagを用いたバブルソート
int bubbleSort(int A[], int N){
    int sw = 0;
    bool flag = 1;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                //隣接要素を交換する
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int A[100],N,sw;
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    sw = bubbleSort(A, N);

    for( int i=0; i<N; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
