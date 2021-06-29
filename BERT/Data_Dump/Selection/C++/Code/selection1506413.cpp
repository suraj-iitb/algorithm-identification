#include <iostream>
using namespace std;


int selectionsort(int A[], int N) {

  int count = 0;
  for (int i = 0; i< N; i++) {

    int minj = i;

    for (int j = i; j < N; j++) {

      if (A[j] < A[minj]) minj = j;
    }

    swap(A[i], A[minj]);
    if (i != minj) count++;
  }
  
  for (int i = 0; i < N; i++) {
    if (i != N-1) cout << A[i] << " ";

    else cout << A[i] << "\n";
  }
  cout << count << "\n";
  
	      
}

int main() {

  int A[100];
  int N;

  cin >> N;

  for (int i=0; i < N; i++) {
    cin >> A[i];
  }

  selectionsort(A, N);
  return 0;
}
