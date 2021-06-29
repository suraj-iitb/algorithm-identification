#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &A, int N) {
  int minj, cnt = 0;
  for(int i = 0; i < N; ++i) {
	minj = i;
	for(int j = i; j < N; ++j) {
	  if(A[j] < A[minj]) minj = j;
	}
	swap(A[i], A[minj]);
	if(i != minj) cnt++;
  }
  /*-- print --*/
  for(int k = 0; k < N; ++k) {
	cout << A[k];
	cout << (k < N - 1 ? " " : "\n");
  }
  cout << cnt << endl;
}
int main() {
  int N;
  cin >> N;
  vector<int> v1(N);
  for(int i = 0; i < N; ++i) {
	cin >> v1[i];
  }
  selectionSort(v1, N);
  return 0;
}
