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

int selectionSort(vector<int> &A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int minj = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(minj != i){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    rep(i, N) scanf("%d", &A[i]);
    int count = selectionSort(A, N);
    rep(i, N){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
}
