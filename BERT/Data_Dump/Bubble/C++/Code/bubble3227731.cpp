#include<iostream>
using namespace std;

int main(){
  int n,sorted=0,counter=0;
  bool flg=true;
  cin >> n;
  int* A = new int[n];

  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  while(flg){
    flg = false;
    for(int i=n-1;i>sorted;i--){
      if(A[i]<A[i-1]){
        A[i] ^= A[i-1]; A[i-1] ^= A[i]; A[i] ^= A[i-1];
	counter++;
	flg = true;
      }
    }
    sorted++;
  }
  for(int i=0;i<n;i++){
    cout <<(i!=0 ? " " : "") << A[i];
  }
  cout << endl << counter << endl;
}
