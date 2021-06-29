#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>& A,int N){
  int c=0;
  rep(i,N){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]) minj = j;
    }
    if(minj != i){
      swap(A[i],A[minj]);
      c++;
    }
  }
  return c;
}

int main() {
  int n;
  cin >> n;
  
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];
  
  int ans=selectionSort(vec,n);
  
  for(int i=0;i<n;i++){
    if(i>0) cout <<" ";
    cout<<vec[i];
  }
  cout<<endl;
  cout<<ans<<endl;
      
  return 0;
}
