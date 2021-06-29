#include <iostream>
using namespace std;

int selectionSort(int A[], int N){
  int i, j, t, cnt = 0, minj;
  for (i = 0; i < N-1; i++) {
    minj = i;
    for (j = i; j < N; j++){
      if (A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
      if (i != minj) cnt++;
      }
  return cnt;
}

int main() {    
  int i, N, cnt, A[100];
  cin >> N;
  for (i = 0; i < N; i++) cin >> A[i];
  cnt = selectionSort(A, N);
  for (i = 0; i < N; i++){
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}
