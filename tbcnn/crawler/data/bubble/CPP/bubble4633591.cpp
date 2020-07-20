#include <bits/stdc++.h>
using namespace std;

int bubblesort(vector<int> &A,int N){
  bool flag=true;
  int count=0;
  for(int i=0;flag;i++){
    flag=0;
    for(int j=N-1;j>i;j--){
      if(A.at(j)<A.at(j-1)){
        swap(A.at(j),A.at(j-1));
        flag=true;
        count++;
      }
    }
  }
  return count;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  int B=bubblesort(A,N);
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
  
