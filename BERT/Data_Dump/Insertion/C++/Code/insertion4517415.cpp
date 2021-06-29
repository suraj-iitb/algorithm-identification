#include<bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  int A[1100];
  
  for(int i =0; i<N ;i++){
    cin >> A[i];
  }
  
  for(int i = 0; i < N; i++){
    int v = A[i];
    int j = i-1;
    while( j >=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v; 
    }
    
    for(int j = 0; j < N; j++){
      if(j == N-1){
        cout << A[j]<< endl;
        break;
      }
      cout << A[j]<< " ";
    }

  }
}


