#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    int v=A[i];
    int j=i-1;
    for(;j>=0 && A[j]>v;j--){
      A[j+1]=A[j];
    }
    A[j+1]=v;
    for(int a=0;a<N;a++){
      cout << A[a];
      if(a!=N-1)cout<<' ';
    }
    cout << endl;
  }
}
    
