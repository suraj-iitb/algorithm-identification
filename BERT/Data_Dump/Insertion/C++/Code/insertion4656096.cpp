#include<iostream>
using namespace std;

int main(){
  int N, A[100], v, j, k;
  
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> A[i];
    cout << A[i];
    if ( i != N-1 ) cout << " ";
    else cout << "\n";
  }

  for ( int i = 1; i < N; i++ ){
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for ( k = 0; k < N; k++ ){
      cout << A[k];
      if ( k != N-1 ) cout << " ";
      else cout << "\n";
    }
  }

  return 0;
}
