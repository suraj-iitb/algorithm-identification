#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;

  cin >> N;

  int *A = new int[N];

  for(int i=0;i<N;++i){
    cin >> A[i];
    
    cout << A[i];
    if(i != N-1) cout << " ";
  }
  cout << endl;

  int j;
  int v;
  for(int i=1;i<N;++i){
    v = A[i];
    for(j = i-1; j>=0; --j){
      if(A[j] > v){
	A[j+1] = A[j];
      }else{
	break;
      }
    }
    A[j+1] = v;
    for(j=0; j<N;++j){
      cout << A[j];
      if(j != N-1) cout << " ";
    }
    cout << endl;
  }


  delete[] A;
}

