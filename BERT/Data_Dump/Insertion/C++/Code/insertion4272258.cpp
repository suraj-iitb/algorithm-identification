#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int A[1000];
  for(int i = 0; i< n;i++){
      cin >>A[i] ;
    cout << A[i];
         if(i!=n-1)cout << ' ';
  }
  cout << endl;
  for(int j=1; j<n;j++){
      int v, k;
      v = A[j];
      k = j-1;
      while(k>=0 && A[k] > v){
          A[k+1]= A[k];
          k--;
      }
      A[k+1] = v;
      for(int i = 0; i<n;i++){
          cout << A[i];
                if(i!=n-1)cout << ' ';
      }
      cout << endl;
  }
}
