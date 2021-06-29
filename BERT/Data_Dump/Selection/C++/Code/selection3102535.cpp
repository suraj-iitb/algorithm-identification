#include<iostream>

using namespace std;

int selection_sort(int A[], int N) {
  int i, j, minj, num = 0;
  for(i = 0; i < N; i++) {
    minj = i;
    for(j = i; j < N; j++) {
      if(A[minj] > A[j]) {
        minj = j;
      }
    }
    if(minj != i) {
      num++;
      swap(A[minj], A[i]);
    }
  }

  return num;
}

int main() {
  int A[100], N, i, num;

  cin>>N;
  for(i = 0; i < N; i++) {
    cin>>A[i];
  }

  num = selection_sort(A, N);

  for(i = 0; i < N; i++) {
    if(i != 0) cout<<" ";
    cout<<A[i];
  }

  cout<<endl<<num<<endl;

  return 0;
}

