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
  for(int i=0;i<N-1;i++){
    int min=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[min]){
         min=j;
      }
    }
    swap(A[i],A[min]);
    if(min!=i){
     sum++;
    }
  }
  for(int i=0;i<N;i++){
    if(i<N-1){
    cout << A[i] << " ";
  }
  else if(i==N-1){
    cout << A[i] << endl << sum << endl;
  }
  }
}
