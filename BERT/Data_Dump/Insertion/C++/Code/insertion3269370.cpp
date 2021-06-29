#include <iostream>
using namespace std;

int main(){
  int A[100], n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int j = 1; j < n; j++){
    for(int i = 0; i < n; i++) cout << A[i] << (i == n-1 ? '\n' : ' ');
    int key = A[j];
    int i = j - 1;
    while(i >= 0 && A[i] > key){
      A[i + 1] = A[i];
      i--;
    }
    A[i + 1] = key;
  }
  for(int i = 0; i < n; i++) cout << A[i] << (i == n-1 ? '\n' : ' ');
  return 0;
}
