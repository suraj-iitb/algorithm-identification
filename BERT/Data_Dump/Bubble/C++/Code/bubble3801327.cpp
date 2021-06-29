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
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = N-1; j >=1; j--) {
      if (A.at(j) < A.at(j-1)) {
        int tmpA = A.at(j);
        A.at(j) = A.at(j-1);
        A.at(j-1) = tmpA;
        num_change++;
        flag = true;
      }
    }
  }
  
  output_vector(A);
  cout << num_change << endl;
  
}
