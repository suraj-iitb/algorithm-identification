#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  int v = 0;
  for(int i = 0;i < N; i++){
    v = A[i];
    int j = i - 1;
    while(j >= 0 && v < A[j]){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(int k = 0; k < N; k++){
      cout << A[k];
      if(k == N - 1){
        cout << endl;
      }else{
        cout << " ";
      }
    }
  }
 
  return 0;
}
