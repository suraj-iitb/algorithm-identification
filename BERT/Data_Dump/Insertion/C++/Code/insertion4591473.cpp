#include <iostream>
using namespace std;

int main(void) {
  int a,N,j,v;
  cin >> N;

  int A[N];

  for (int k=0;k<N;k++){
    cin >> a;
    A[k] = a;
  }

  for (int i=1;i<N;i++){
    for (int l=0; l<N-1; l++){
      cout << A[l] << " ";
    }
    cout << A[N-1] <<endl;
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  for (int l=0; l<N-1; l++){
    cout << A[l] << " ";
  }
  cout << A[N-1] <<endl;
  return 0;
}

