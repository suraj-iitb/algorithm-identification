#include <iostream>

using namespace std;

int main() {
  int N;
  int A[100];
  
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  
  for (int i=0; i<N; i++) {
    int v = A[i];
    
    int j;
    for (j = i-1; j >= 0 && A[j] > v; j--) A[j+1] = A[j];

    A[j+1] = v;
    for (int k=0; k<N; k++) {
      cout << A[k];
      if (k != N-1) cout << " ";
    }
    cout << endl;
  }
  
  return 0;
}
