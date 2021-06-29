#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  int A[N];
  for(int i = 0; i < N; i++){
    cin >> A[i];
//    cout << A[i] << endl;
  }

  int count = 0;
  int flag = 1;

  while(flag){
    flag = 0;
    for(int i = N-1; i > 0; i--){
      if(A[i-1] > A[i]){
        swap(A[i-1],A[i]);
        flag = 1;
        count++;
      }
    }
  }

  for(int k = 0; k < N; k++){
    cout << A[k];
    if(k == N - 1){
      cout << endl;
    }else{
      cout << " ";
    }
  }

  cout << count << endl;

  return 0;
}
