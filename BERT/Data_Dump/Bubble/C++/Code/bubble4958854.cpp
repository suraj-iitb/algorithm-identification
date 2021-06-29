#include <bits/stdc++.h>
using namespace std;

//バブルソート
int bubbleSort(vector<int> &A, int N){
  int cnt=0;
  bool flag = 1;
  for(int i=0; flag; i++){
    flag = 0;
    for(int j=N-1; j>=i+1; j--){
      if(A.at(j) < A.at(j-1)){
        swap(A.at(j),A.at(j-1));
        flag = 1;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){

  int N,cnt;
  cin >> N;

  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }

  cnt = bubbleSort(A,N);

  for(int i=0; i<N; i++){
    if(i>0) cout << " ";
    cout << A.at(i);
  }

  cout << endl;
  cout << cnt << endl;

  return 0;

}
