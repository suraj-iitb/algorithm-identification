#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int cnt=0;
void selectionSort(vector<int> &A,int N){ // N個の要素を含む0-オリジンの配列A
    for(int i=0;i<=N-1;i++){
      int minj=i;
      for(int j=i;j<=N-1;j++){
        if(A[j]<A[minj]){
          minj = j;
        }
      }
      if(minj!=i){
        cnt++;
        swap(A[i],A[minj]);
      }
      
    }
}

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  selectionSort(A,N);
  for(int i=0;i<N;i++){
    cout<<A[i];
    if(i<N-1){cout<<" ";}
  }
  cout<<endl;

  cout<<cnt<<endl;
  return 0;  
}
