#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

void output(vector<int> B, int s) {
    rep(i, s - 1) cout << B.at(i) << " ";
    cout << B.at(s - 1) << endl;
}


int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A.at(i);
  int counter = 0;

  rep(i,N){
    int minj = i;
    for(int j = i; j < N;j++){
      if(A.at(j) < A.at(minj)) minj = j;
    }
    if(i != minj) counter++;
    swap(A.at(i),A.at(minj));
  }
  output(A,N);
  cout << counter << endl;
}

