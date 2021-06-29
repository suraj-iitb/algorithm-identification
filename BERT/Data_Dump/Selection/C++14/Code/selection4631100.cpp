#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD7 1000000007
#define LL_INF 1LL << 60
#define LL_MINF -1LL << 60
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long double PI = (acos(-1));

int selectionSort(vector<int> &A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int min_j = i;
        for(int j = i; j < N; j++){
            if(A[j] < A[min_j]) {
                min_j = j;
            }
        }
        swap(A[i], A[min_j]);
        if(min_j != i) count++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int n = selectionSort(A, N);
    for(int i = 0; i < N; i++){
        cout << A[i];
        if(i != N - 1) cout << ' ';
    }
    cout << endl;
    cout << n << endl;
}
