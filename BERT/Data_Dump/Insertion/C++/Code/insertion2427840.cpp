#include <iostream>
using namespace std;
void insertionsort(int *A, int N) {
  int v, i, j, k;
  for(i = 1; i <= N - 1; i++) {
	v = A[i];
	j = i - 1;
	while(j >= 0 && A[j] > v) {
	  A[j + 1] = A[j];
	  j--;
	}
	A[j + 1] = v;

	for(k = 0; k < N; k++) {
	  cout << A[k];
	  if(k < N - 1) {
		cout << " ";
	  }
	}
	cout << endl;
  }
}
int main() {
  int i, N, num;
  int A[1000];
  cin >> N;
  for(i = 0; i < N; i++) {
	cin >> num;
	A[i] = num;
  }
  for(i = 0; i < N; i++) {
	cout << A[i];
	if(i < N - 1) {
	  cout << " ";
	}
  }
  cout << endl;
  insertionsort(A, N);
  return 0;
}
