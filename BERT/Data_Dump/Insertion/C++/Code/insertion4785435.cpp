#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

void insertionSort(vector<int>A, int N){ // N個の要素を含む0-オリジンの配列A
  for(int i=1;i<=N-1;i++){
   int v = A[i];
   int j = i - 1;
   while (j >= 0 && A[j] > v){
    A[j+1] = A[j];
    j--;
   }
    A[j+1] = v;
   for(int i=0;i<N;i++){
     cout<<A[i];
     if(i<N-1){cout<<" ";}
   }cout<<endl;
  }
}

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
     cout<<A[i];
     if(i<N-1){cout<<" ";}
  }cout<<endl;
  
  insertionSort(A,N);
  return 0;  
}
