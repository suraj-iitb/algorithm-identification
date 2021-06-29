#include<bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
  int counter = 0;
  for (int i=0; i<N; i++) {
    int minj = i;
    for (int j=i; j<N; j++) {
      if (A[j]<A[minj]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) counter++;
  }
  return counter;
}

int main() {
  int N, A[100];
  cin >> N;

  for (int i=0; i<N; i++) cin >> A[i];

  int counter = selectionSort(A, N);
  
  for (int i=0; i<N; i++) {
    if (i>0) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << counter << endl;
}
