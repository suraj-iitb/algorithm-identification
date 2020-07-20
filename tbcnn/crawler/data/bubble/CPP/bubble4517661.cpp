#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[110];
  for(int i = 0; i <N; i++){
    cin >> A[i];
  }
  
  bool flag = 1;
  int cnt = 0;
  while (flag){
    flag = 0;
    for(int j =1; j < N ;j++){
      if(A[j] < A[j-1]){
        swap(A[j],A[j-1]);
        cnt++;
        flag = 1;
      }
    }
  }
  for(int i =0; i <N; i++){
    if(i == N-1){
      cout << A[i];
      break;
    }
    cout << A[i] << " ";
  }
  cout << endl;
  cout << cnt << endl;
}

