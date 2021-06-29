#include <bits/stdc++.h>
using namespace std;

int SelectionSort(vector<int> &A, int N){
  int cnt = 0;
  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A.at(j) < A.at(minj)){
        minj = j;
      }
    }
    if(minj != i){
      swap(A.at(i), A.at(minj));
      cnt++;
    }
  }
  return cnt;
}

int main(){
	int n;
  cin >> n;
  vector<int> A(n);

  for(int i = 0; i < n; i++){
    cin >> A.at(i);
  }

  int result = SelectionSort(A, n);

  for (size_t i = 0; i < n-1; i++) {
    cout << A.at(i) << " ";
  }
  cout << A.at(n-1) << endl;

  cout << result << endl;

}

