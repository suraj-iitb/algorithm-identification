// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N; 
    scanf("%d", &N);
    vector<int> A(N);
    rep(i, N) scanf("%d", &A[i]);
    int flag = 1, ans = 0;
    while(flag){
        flag = 0;
        for(int j = N -1; j >=0 ; j--){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j-1]);
                flag = 1;
                ans++;
            }
        }
    }
    rep(i, N){
        printf("%d", A[i]);
        if(i != N - 1) printf(" ");
        else printf("\n");
    }
    printf("%d\n", ans);
}
