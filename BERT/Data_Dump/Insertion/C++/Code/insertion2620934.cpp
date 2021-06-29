#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

void insertionSort(int A[], int N) {
  for(int i = 0; i < N; i++) {
    cout << A[i];
    if(i != N - 1)
      cout << ' ';
  }
  cout << endl;
  for (int i = 1; i <= N - 1; i++) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    for (int k = 0; k < N; k++) {
      cout << A[k];
      if (k != N - 1) cout << ' ';
    }
    cout << endl;
  }
}

int main(void) {
  int N, i = 0;
  cin >> N;
  cin.ignore();
  int A[N];
  string str;
  getline(cin, str);
  istringstream s(str);
  while (getline(s, str, ' ')) {
    A[i++] = atoi(str.c_str());
  }
  insertionSort(A, N);
  return 0;
}
