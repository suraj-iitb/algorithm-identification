#include<iostream>
using namespace std;

void trace(int A[], int N) {
  for (int i=0; i<N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

int insertionsort(int A[], int N) {
  for (int i=0; i<N; i++) {
    int tmp = A[i];
    int j = i-1;
    while(A[j]>tmp && j>=0) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = tmp;
    trace(A, N);
  }
}

int main(){
  int A[100], N;
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> A[i];
  }
  insertionsort(A, N);

  return 0;
}
