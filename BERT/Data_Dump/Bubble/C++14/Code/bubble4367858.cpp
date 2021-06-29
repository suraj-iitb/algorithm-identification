
#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int M,vector<int> &A){
  bool flag = true;
  int s = 0;
  
  while(flag){
    flag = false;
    for(int j=M-1;j>=1;--j){
      if(A.at(j) < A.at(j-1)){
        swap(A.at(j),A.at(j-1));
        s += 1;
        flag = true;
      }
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

  cnt = bubbleSort(N,vec);
  for(int i=0;i<N-1;++i){
  cout << vec.at(i) << " ";
  }
  cout << vec.at(N-1) << endl;
  cout << cnt << endl;
}

