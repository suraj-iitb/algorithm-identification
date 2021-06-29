#include <bits/stdc++.h>
using namespace std;

int selectionsort(vector<int> &A,int N){
  int count=0;
  for(int i=0;i<N-1;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A.at(j)<A.at(minj)){
        minj=j;
      }
    }
    swap(A.at(i),A.at(minj));
    if(i!=minj){
      count++;
    } 
  }
  return count;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  int B=selectionsort(A,N);
  for(int i=0;i<N;i++){
    cout << A.at(i);
    if(i!=N-1){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
  cout << B << endl;
}
