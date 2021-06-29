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

ll cm = 0;

void merge(vector<int> &A, int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i] < R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cm++;
    }
}

void mergeSort(vector<int> &A, int left, int right){
    if(right - left > 1){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    mergeSort(A, 0, N);
    rep(i, N){
        if(i != N - 1) cout << A[i] << ' ';
        else cout << A[i] << endl;
    }
    cout << cm << endl;
}
