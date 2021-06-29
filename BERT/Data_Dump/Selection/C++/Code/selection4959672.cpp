#include <bits/stdc++.h>
using namespace std;

//セレクションソート
int selectionSort(vector<int> &A, int N){
  int cnt=0, minj;
  for(int i=0; i<N-1; i++){
    minj = i;
    for(int j=i; j<N; j++){
      if(A.at(j) < A.at(minj)) minj = j;
    }
    swap(A.at(i),A.at(minj));
    if(i != minj) cnt++;
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

  cnt = selectionSort(A,N);

  for(int i=0; i<N; i++){
    if(i>0) cout << " ";
    cout << A.at(i);
  }

  cout << endl;
  cout << cnt << endl;

  return 0;

}
