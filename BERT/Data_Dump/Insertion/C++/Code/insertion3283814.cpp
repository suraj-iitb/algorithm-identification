#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> A, int N){
  for (int i=1; i<N; i++){
    int v = A.at(i);
    for (int j = i-1; j >=0; j--){
      if(v < A.at(j)){
        A.at(j +1) = A.at(j);
        A.at(j) = v;
      }
      else
        break;
    }

    for(int i =0; i<N;i++){
      if(i>0)
        cout <<' ';
      cout << A.at(i);
    }

    cout << endl;
  }
}



int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N;i++)
    cin >> A.at(i);
  for (int i=0; i<N;i++){
    if(i>0)
      cout << ' ';
    cout <<  A.at(i);
  
  }
  cout << endl;


  insertionSort(A, N);
}
