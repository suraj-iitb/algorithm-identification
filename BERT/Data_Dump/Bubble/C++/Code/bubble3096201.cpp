#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int sum=0;
  for(int i=0;i<N;i++){
    for(int j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        sum++;
      }
    }
    if(i==N-1){
      for(int k=0;k<N;k++){
        if(k<N-1){
        cout << A[k] << " ";
      }
      else if(k==N-1){
        cout << A[k];
      }
      }
      cout << endl << sum << endl;
    }
  }
}
