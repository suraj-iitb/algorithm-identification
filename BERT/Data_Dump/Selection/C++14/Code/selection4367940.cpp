
#include <bits/stdc++.h>
using namespace std;

int selectionSort(int M,vector<int> &A){
  int s = 0;

  for(int i=0;i<M;++i){
    bool flag = false;
    int minj = i;
    for(int j=i;j<M;++j){
      if(A.at(j) < A.at(minj)){
        minj = j;
        flag = true;
      }
    }
    if(flag){
      swap(A.at(i),A.at(minj));
      s += 1;
    }
  }
  return s;
}
int main(){
  int N;
  int cnt;

  cin >> N;
  vector<int> vec(N);
  for(int i=0;i<N;++i){
    cin >> vec.at(i);
  }

  cnt = selectionSort(N,vec);
  for(int i=0;i<N-1;++i){
    cout << vec.at(i) << " ";
  }
    cout << vec.at(N-1) << endl;
    cout << cnt << endl;
}

