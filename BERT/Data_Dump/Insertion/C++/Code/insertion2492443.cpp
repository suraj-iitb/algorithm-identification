#include <iostream>

using namespace std;

int main() {
  int N;
  int a[100];
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int key;
  for (int i = 1; i < N; i++) {
     for (int k = 0; k < N - 1; k++) {
      cout << a[k] << " ";
    }
    cout << a[N-1] << endl;
    key = a[i];
    int j = i - 1;
    while (j>=0 && a[j] > key) {
      a[j+1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
  for (int k = 0; k < N - 1; k++) {
      cout << a[k] << " ";
    }
    cout << a[N-1] << endl;
  return 0;
}
    
