#include <bits/stdc++.h>
using namespace std;

vector<int> Bubble_Sort(vector<int> &A, int N, int &cnt){
  bool flag = 1;
  while(flag){
    flag = 0;
    for(int j = N - 1; j >= 1; j--){
      if(A.at(j) < A.at(j - 1)){
        int X = A.at(j - 1);
        A.at(j - 1) = A.at(j);
        A.at(j) = X;
        flag = 1;
        cnt++;
      }
    }
  }
  return A;
}

int main(){
  int N;
  int cnt = 0;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  Bubble_Sort(A, N, cnt);
  for(int i = 0; i < N - 1; i++){
    cout << A.at(i) << " ";
  }
  cout << A.at(N - 1) << endl;
  cout << cnt << endl;
}

