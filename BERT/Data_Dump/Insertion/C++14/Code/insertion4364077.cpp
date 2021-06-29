
#include <bits/stdc++.h>
using namespace std;

void intsertionSort(int N,vector<int> &A){
  int v;
  int j;

  for(int i=1;i<=N-1;++i){
    v = A.at(i);
    j = i - 1;
    while(j >= 0 && A.at(j) > v){
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;
    for(int k=0;k<N-1;++k){
      cout << A.at(k) << " ";
    }
      cout << A.at(N-1) << endl;
    }
}
int main(){
  int N;

  cin >> N;
  vector<int> vec(N);
  for(int i=0;i<N;++i){
    cin >> vec.at(i);
  }
  for(int i=0;i<N-1;++i){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(N-1) << endl;
  intsertionSort(N,vec);


}

