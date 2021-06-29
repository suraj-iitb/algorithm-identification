#include<iostream>
using namespace std;

int bubblesort(int A[], int N) {
  int cnt=0;
  int tmp;
  for(int i=0; i<N-1; i++) {
    for(int j=N-1; j>i; j--) {
      if(A[j] < A[j-1]) {
        tmp = A[j-1];
        A[j-1] = A[j];
        A[j] = tmp;
        cnt++;
      }
    }
  }
  return cnt;
}

int swap(int A[], int B[]){

}

int main(){
  int A[100], N, cnt;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  cnt = bubblesort(A, N);

  for(int i=0; i<N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}
