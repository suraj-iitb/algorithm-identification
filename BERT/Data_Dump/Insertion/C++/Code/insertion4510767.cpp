// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N;
    cin >> N; 
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
        cout << A[i];
        if(i != N - 1) cout << ' ';
        else cout << endl;
    }

    for(int i = 1; i < N; i++){
        int v = A[i];
        int j = i - 1;
        while( j >= 0 && v < A[j]){
            A[j + 1] = A[j];
            A[j] = v;
            j--;
        }
        rep(j, N){
            cout << A[j];
            if(j != N - 1) cout << ' ';
            else cout << endl;
        }
    }
}
