#include <bits/stdc++.h>
using namespace std;


int main(){
  int n,sw=0;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  bool flag=1;
  for(int i=0;flag;i++){
    flag=0;
    for(int j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        sw++;
        flag=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i){cout <<" ";}
    cout << A[i];
  }
  cout << endl<<sw<<endl;
}
