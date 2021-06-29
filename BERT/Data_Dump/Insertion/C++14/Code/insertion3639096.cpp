#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N){
  for(int i = 0; i < N; i++){
    if(i < N - 1) {
      cout << A[i] << " ";
    } else {
      cout << A[i] << endl;
    }
  }
}

// int insertionSort(vector<int> A, int N) {
void insertionSort(int A[], int N){
    for (int i = 1; i < N; i++) {
      // int v = A.at(i);
      int v = A[i];
      int j = i - 1;
      // while(j >= 0 && A.at(j) > v) {
      while(j >= 0 && A[j] > v) {
        // A.at(j+1) = A.at(j);
        A[j+1] = A[j];
        j--;
      }
      // A.at(j+1) = v; // 最後はj=-1となる
      A[j+1] = v;
      trace(A, N);
    }
}


int main() {
  int N;
  cin >> N;
  // vector<int> A(N);
  int A[N];
  // for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> A[i];
  trace(A, N);
  insertionSort(A, N);

}

