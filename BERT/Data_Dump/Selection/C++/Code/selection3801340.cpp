#include<bits/stdc++.h>
using namespace std;

void output_vector(vector<int> &A) {
  int vector_size = A.size();
  
  for (int i = 0; i < vector_size-1; i++) {
    cout << A.at(i) << " ";
  }
  cout << A.at(vector_size-1) << endl;
}

int main() {
  int N, v, j;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  int num_change = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      int tmpA = A.at(i);
      A.at(i) = A.at(minj);
      A.at(minj) = tmpA;
      num_change++;
    }
  }
  
  output_vector(A);
  cout << num_change << endl;
  
}
