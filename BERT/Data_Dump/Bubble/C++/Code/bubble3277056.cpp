#include <iostream>
using namespace std;

int bubblesort(int *A, int N){
  int cnt = 0;
  for(int i = 0; i < N - 1; i++){
    for(int j = N - 2; j >= i; j--){
      if(A[j] > A[j+1]){
	int tmp = A[j];
	A[j] = A[j+1];
	A[j+1] = tmp;
	cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int A[100], n, cnt;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  cnt = bubblesort(A, n);
  for(int i = 0; i < n; i++) cout << A[i] << (i == n - 1 ? '\n' : ' ');
  cout << cnt << endl;
  return 0;
}
