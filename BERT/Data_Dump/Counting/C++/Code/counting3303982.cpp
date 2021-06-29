#include <iostream>
using namespace std;

int main(){
  int A[2000001], B[2000001], C[10001], n;
  for(int i = 0; i <= 10000; i++) C[i] = 0;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> A[i];
    C[A[i]]++;
  }
  for(int i = 1; i <= 10000; i++) C[i] += C[i-1];
  for(int i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(int i = 1; i <= n; i++) cout << B[i] << (i == n ? '\n' : ' ');
  return 0;
}
