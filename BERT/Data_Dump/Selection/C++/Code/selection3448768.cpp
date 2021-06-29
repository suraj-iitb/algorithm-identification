#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[101];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  int count = 0;
  for(int i = 0 ; i < N; i++){
    int a = A[i];
    int minj;
    for(int j=i+1; j<N; j++){
      if(A[j] < a){
	a = A[j];
	minj = j;
      }
    }
    if(a < A[i]){
      count++;
      A[minj] = A[i];
      A[i] = a;
    }
  }

  for(int i=0; i<N; i++){
    if(i > 0)cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << count << endl;
  
  return 0;
}

