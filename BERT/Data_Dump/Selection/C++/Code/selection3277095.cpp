#include <iostream>
using namespace std;

int selectionsort(int *A, int N){
  int cnt = 0;
  for(int i = 0; i < N -1; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(i != minj){
      int tmp = A[minj];
      A[minj] = A[i];
      A[i] = tmp;
      cnt++;
    }
  }
  return cnt;
}

int main(){
  int A[100], n, cnt;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  cnt = selectionsort(A, n);
  for(int i = 0; i < n; i++) cout << A[i] << (i == n - 1 ? '\n' : ' ');
  cout << cnt << endl;
  return 0;
}
