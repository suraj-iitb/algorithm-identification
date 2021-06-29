#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

void SelectionS(int N, vector<int> &A, int &c){
  rep(i, N){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A.at(j) < A.at(minj)){
        minj = j;
      }
    }
    if(minj!=i){
      swap(A.at(i), A.at(minj));
      c++;
    }
  }
}

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }

  int counter = 0;

  SelectionS(N, A, counter);

  rep(i, N){
    cout <<A.at(i);

    if(i != N-1) cout << " ";
    else cout << endl;
  }

  cout << counter << endl;
}

