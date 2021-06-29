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
  output_vector(A);
  
  for (int i = 1; i < N; i++) {
  	v = A.at(i);
  	j = i - 1;
  	while (j >= 0 && A.at(j) > v) {
  		A.at(j+1) = A.at(j);
  		j--;
  	}
  	A.at(j+1) = v;
  	
    output_vector(A);
    
  }
  
}
