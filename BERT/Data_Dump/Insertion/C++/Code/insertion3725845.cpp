#include<iostream>
using namespace std;
static const int MAX = 100;

void insertionSort(int A[], int N){
  for ( int i = 0; i < N; i++ ) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(int k = 0; k < N; k++ ){
      cout << A[k];
      if (k != N-1) cout << ' ';
    }
   cout << endl;
  }
}

int main()
{
  int R[MAX], N;

  cin >> N;
  for ( int i = 0; i < N; i++ ) cin >> R[i];
  insertionSort(R, N);

  return 0;
}

