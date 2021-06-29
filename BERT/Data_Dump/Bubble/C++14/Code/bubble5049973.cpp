#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }

  int flag = 1;
  int cnt = 0;
  while(flag){
    flag = 0;
    for(int j=N-1;j>0;j--){
      if(A.at(j) < A.at(j-1)){
        int tmp = A.at(j);
        A.at(j) = A.at(j-1);
        A.at(j-1) = tmp;
        flag = 1;
        cnt++;
      }
    }
  }

  for(int i=0;i<N;i++){
    if(i != N-1) cout << A.at(i) << " ";
    else cout << A.at(i) << endl;
  }
  cout << cnt << endl;
}
