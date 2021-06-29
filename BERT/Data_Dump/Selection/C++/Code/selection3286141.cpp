#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> A, int N){
  int min = A.at(0);
  int min_i;
  int count =0;
  bool flag;
  for(int i=0; i<N; i++){
    flag = 0;
    min = A.at(i);
    for(int j = i; j<N; j++){
      if(min > A.at(j)){
        min = A.at(j);
        flag = 1;
        min_i = j;
      }
    }
    if(flag){
      swap(A.at(i), A.at(min_i));
      count ++;
    }
  }
  for(int i=0;i<N;i++){
    if(i < N-1)
      cout << A.at(i) << ' ';
    else
      cout << A.at(i) << endl;
  }
  cout << count << endl;
}



int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N;i++)
    cin >> A.at(i);

  SelectionSort(A,N);
}

