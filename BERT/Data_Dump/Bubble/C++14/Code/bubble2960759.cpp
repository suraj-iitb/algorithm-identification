#include <iostream>
using namespace std;
int bubbleSort(int N, int A[]){
  int sw = 0;
  for(int j = 0; N > j; j++){
    for(int i = N - 1; i > j; i--){
      if(A[i] < A[i - 1]){
        swap(A[i], A[i - 1]);
        sw++;
      }
    }
  }
  for(int i = 0; N > i; i++){
    cout << A[i];
    if(N != i + 1){
      cout << " ";
    }
  }
  cout << endl;
  cout << sw << endl;
}
int main(){
  int N;
  cin >> N;
  int A[N];
  for(int i = 0; N > i; i++) cin >> A[i];
  bubbleSort(N,A);
}
