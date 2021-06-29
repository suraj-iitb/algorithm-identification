#include <iostream>
using namespace std;

void PrintArray(int A[], int N) {
  for (int i = 0; i < N-1; i++) {
    cout << A[i] << " ";
  }
  cout << A[N-1] << endl;
}

int main() {
  int N; 
  int A[1010];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    int j = i-1;
    int temp = A[i];
    while (j >= 0 && A[j] > temp) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
    PrintArray(A, N);
  }
}


