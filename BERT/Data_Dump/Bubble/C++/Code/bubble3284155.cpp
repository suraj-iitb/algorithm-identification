#include<bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& A, int N){
  int res =0;
  for(int i=0; i<N; i++){//while 使えば短縮できるが。まずはforで愚直にやるのも良い
    for(int j = N-1; j > i; j--){
      if(A.at(j) < A.at(j - 1)){
        swap(A.at(j), A.at(j-1));
        res ++;
      }
    }
  }
  return res;
}



int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)
    cin >> A.at(i);

  int res = bubbleSort(A, N);
  for(int i=0; i<N; i++){
    if(i)
      cout<<' ';
    cout << A.at(i);
  }
  cout << endl << res << endl;
}


                                                          
