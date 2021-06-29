#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    REP(i, N) {
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;        
        REP(k, N) cout << A[k] << (k!=N-1 ? " " : "");
        cout << endl; 
    }
}
