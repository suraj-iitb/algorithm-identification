#include<iostream>
using namespace std;
typedef unsigned short u_short;
static const int SIZE = 2000001;
static const int MVALUE = 10000;

void countingSort(u_short *A, u_short *B, int n, int k){
  int C[k+1];
  for(int i=0; i<k; i++) C[i] = 0;
  for(int j=1; j<=n; j++) C[A[j]]++;
  for(int i=1; i<k; i++) C[i] += C[i-1];
  for(int j=1; j<=n; j++){B[C[A[j]]] = A[j]; C[A[j]]--;}
  return;
}

void print(u_short *A, int n){
  for(int i=1; i<=n; i++){
    if(i>1) cout << " ";
    cout << A[i];
  }
  cout << endl;
  return;
}

int main(){
  int n;
  u_short A[SIZE], B[SIZE];

  cin >> n;
  for(int i=1; i<=n; i++) cin >> A[i];

  countingSort(A, B, n, MVALUE);
  print(B, n);

  return 0;
}

