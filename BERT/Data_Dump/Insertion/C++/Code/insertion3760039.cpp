#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

void trace(vector<int> A, int N){
  int i;
  REP(i,N){
    if(i > 0)cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}

void inseringsort(vector<int>A, int N){
  int j,i,v;
  REP(i,N){
    if(i ==0)continue;
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]= v;
    trace(A,N);
  }
}

int main(){
int N,i,j;
cin >> N;
vector<int> A(100);
REP(i,N) cin >> A.at(i);
trace(A,N);
inseringsort(A,N);
return 0;
}

