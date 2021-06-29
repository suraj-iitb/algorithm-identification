#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> A, int N)
{
  for(int i = 0; i < N - 1; i++) {
    cout << A[i] << " ";
  }
  cout << A[N - 1] << endl;
}

void insertionSort(vector<int> A, int N)
{
  for(int i = 1; i < N; i++) {
    printvec(A, N);
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  printvec(A, N);
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  insertionSort(A, N);
  return 0;
}
