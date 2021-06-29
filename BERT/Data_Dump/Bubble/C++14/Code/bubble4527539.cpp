#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

void Bubble_Sort(int N, vector<int> &A, int &c){
  bool flag = true;

  while(flag){
    flag = false;
    for(int j = N-1; j > 0; j--){
      if(A.at(j) < A.at(j -1)){
        swap(A.at(j), A.at(j-1));
        flag = true;
        c++;
      }
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
  Bubble_Sort(N, A, counter);

  rep(i, N){
    cout << A.at(i);
    if(i != N-1) cout << " ";
    else cout << endl;
  }

  cout << counter <<endl;
}

