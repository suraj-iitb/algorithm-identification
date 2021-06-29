#include <iostream>
using namespace std;
 
int main() {
  int num;
  cin >> num;
 
  int *A;
  A = new int[num];
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
 
  int numSwap = 0;
  for (int i = 0; i < num - 1; i++) {
    for (int j = num - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        numSwap++;
      }
    }  
  }
 
  for (int i = 0; i < num - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[num - 1] << endl;
  cout << numSwap << endl;

  return 0;
}
