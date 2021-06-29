#include<bits/stdc++.h>
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

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

void trace(int A[],int N){
  REP(i,N){
    if(i>0){
      cout<<" ";
    }
    cout<<A[i];
  }
  cout<<endl;
}
void insertionSort(int A[],int N){
  int j,v;
  FOR(i,1,N){
    v=A[i];
    j=i-1;
    while (j>=0&&A[j]>v) {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    trace(A,N);
  }
}

int main(void){
    int N;
    int A[100];
    cin>>N;
    REP(i,N){
      cin>>A[i];
    }
    trace(A,N);
    insertionSort(A,N);


    return 0;
}

