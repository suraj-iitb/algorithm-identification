#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)g
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int selectionsort(vector<int>&A, int N){
  int i,j,t, sw =0,minj;
  REP(i,N-1){
    minj = i;
    FOR(j,i,N){
      if(A[j] <A[minj]) minj = j;
    }
    t =A[i]; A[i] = A[minj]; A[minj] = t;
    if(i != minj)sw++;
  }
  return sw;
}

int main(){
int N,i,sw;
cin >> N;
vector<int> A(100);
REP(i,N) cin >> A[i];
sw = selectionsort(A,N);

REP(i,N){
  if(i > 0) cout << " ";
  cout << A[i];
}
cout <<endl;
cout << sw<<endl;
return 0;
}

