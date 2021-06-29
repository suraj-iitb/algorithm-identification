#include<iostream>
using namespace std;

const int N = 100;

void print(int n, int A[]) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void insertion_sort(int n, int A[]) {
  int i, j, v;
  
  for (i = 0; i < n; i++) {
    v = A[i];
    
    for (j = i-1; j >= 0; j--) {
      if (A[j] > v) {
        A[j+1] = A[j];
      } else {
        break;
      }
    }
    A[j+1] = v;
    
    print(n, A);
  }
}

int main() {
  int n;
  int A[N];    

  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  insertion_sort(n, A);

  return 0;
}

