#include <bits/stdc++.h>
using namespace std;

void output (vector<int> &A,int N){
  for(int i=0;i<N;i++){
    cout << A.at(i);
    if(i!=N-1){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
  return;
}

void intentionsort(vector<int> &A,int N){
  for(int i=1;i<N;i++){
    int V=A.at(i);
    int j=i-1;
    while(j>=0 && A.at(j)>V){
      A.at(j+1)=A.at(j);
      j--;
    }
    A.at(j+1)=V;
    output(A,N);
  }
  return;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    cout << A.at(i);
    if(i!=N-1){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
  intentionsort(A,N);
  
}
