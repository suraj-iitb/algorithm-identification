#include<iostream>
  
using namespace std;

void bubbleSort(int A[], int N) {
  int flag = 1;
  int count = 0;
  while (flag) {
    flag = 0;
    for (int j = N-1; j > 0; j--) {
      if (A[j] < A[j-1]) {
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        count++;
        flag = 1;
      }
    }
  }

  cout << A[0];
  for (int i = 1; i < N; i++) cout << " " << A[i];
  cout << endl;

  cout << count << endl;
}

int main() {
   int N, A[100];

   cin >> N;
   for(int i = 0; i < N; i++) cin >> A[i];

   bubbleSort(A, N);
}

