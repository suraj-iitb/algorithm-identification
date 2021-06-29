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



void trace(int A[], int N){
  int i;
  REP(i,N){
    if(i > 0)cout << " ";
    cout << A[i];
  }
  cout << endl;
}

int bubblesort(int A[], int N){
  int sw;
  sw =0;
  bool flag =1;
  for(int i =0; flag;i++){
    flag =0;
    FORR(j,N-1,i+1){
      if (A[j-1] > A[j]){
        swap(A[j-1],A[j]);
        flag =1;
        sw++;
      }
    }
  }
  return sw;
}

int main(){
int N,sw;
cin >> N;
int A[100];
REP(i,N) cin >> A[i];
sw = bubblesort(A,N);

REP(i,N){
  if(i) cout << " ";
  cout << A[i];
}
cout << endl;
cout << sw <<endl;

return 0;
}

