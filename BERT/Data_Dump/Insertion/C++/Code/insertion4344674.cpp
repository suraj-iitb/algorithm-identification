#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(),(x).end()

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int vec[n];
  
  rep(i,n) cin >> vec[i];
  
  for(int k=0;k<n;k++){
    if(k>0) cout << " ";
    cout << vec[k];
  }
  cout << endl;
  
  for(int i=1;i<n;i++){
    int v = vec[i];
    int j=i-1;
    while(j>=0 && vec[j]>v){
      vec[j+1]=vec[j];
      j--;
    }
    vec[j+1]=v;
    
    for(int k=0;k<n;k++){
      if(k>0) cout << " ";
      cout << vec[k];
    }
    cout << endl;
  }
      
  return 0;
}
