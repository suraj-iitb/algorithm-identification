#include <iostream>
#include <vector>
using namespace std;
#define MAX 10100

void Print(vector<int> A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i];
    if (i != A.size()-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}

int main() {
  int N; cin >> N;
  vector<int> A(N), C1(MAX, 0), C2(MAX, 0), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    C1[A[i]]++;
  }
  C2[0] = C1[0];
  for (int i = 1; i < MAX; i++) {
    C2[i] += C2[i-1] + C1[i];
  }
  for (int i = N-1; i >= 0; i--) {
    B[C2[A[i]]-1] = A[i];
    C2[A[i]]--;
  }
  Print(B);
}


