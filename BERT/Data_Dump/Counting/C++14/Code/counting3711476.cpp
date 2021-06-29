#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N; cin >> N;
    int A[N+1], B[N+1];
    int C[10005] = {};

    for(int i=0; i<N; ++i){
        scanf("%d", &A[i+1]);
        ++C[A[i+1]];
    }

    for(int i=1; i<=10000; ++i) C[i] = C[i-1]+C[i];

    for(int j=1; j<=N; ++j){
        B[C[A[j]]] = A[j];
        --C[A[j]];
    }

    for(int i=1; i<=N; ++i){
        if(1 < i) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
