#include<iostream>
using namespace std;

int main(){
  int n,counter=0;
  cin >> n;
  int* A = new int[n];

  for(int i=0;i<n;i++) cin >> A[i];

  for(int i=0;i<n;i++){
    int minj = i;
    for(int j=i;j<n;j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(minj != i){
      A[i] ^= A[minj]; A[minj] ^= A[i]; A[i] ^= A[minj];
      counter++;
    }
  }
  for(int i=0;i<n;i++){
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl << counter << endl;
  delete[] A;
}
