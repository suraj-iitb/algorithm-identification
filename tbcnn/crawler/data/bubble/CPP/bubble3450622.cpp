#include <iostream>
using namespace std;

int bubbleSort(int A[], int N){
  int sw = 0;
  for(int i = 0; i < N; i++)
    for(int j = N - 1; j > i; j--){
      if(A[j] < A[j-1]){
        swap(A[j], A[j-1]);
        sw++;
    }
  }
  return sw;
}


int main(){
  int A[100], N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  int sw =  bubbleSort(A, N);
  
  for(int i = 0; i < N; i++){
    if(i) cout << ' ';
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;
  
  return 0;
}



