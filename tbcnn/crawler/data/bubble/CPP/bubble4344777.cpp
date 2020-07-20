#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& A,int N){
  int c=0;
  bool flag=1;
  while(flag){
    flag=0;
    for(int j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
        int v=A[j];
        A[j]=A[j-1];
        A[j-1]=v;
        c++;
        flag=1;
      }
    }
  }
  return c;
}

int main() {
  int n;
  cin >> n;
  
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];
  
  int ans=bubbleSort(vec,n);
  
  for(int i=0;i<n;i++){
    if(i>0) cout <<" ";
    cout<<vec[i];
  }
  cout<<endl;
  cout<<ans<<endl;
      
  return 0;
}
