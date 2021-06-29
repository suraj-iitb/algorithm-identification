#include <iostream>
#include <array>

#include <cstdio>

using namespace std;

static void printArray(int A[], int N) {
  for (auto i = 0; i < N; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl; 
}

static int bubbleSort(int A[], int N) {
  bool flag = true;
  int count = 0, tmp;
  int i = 0;
  while (flag) {
    flag = false;
    for (auto j = N - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
	tmp = A[j - 1];
	A[j - 1] = A[j];
	A[j] = tmp;
	flag = true;
	count++;
      }
    }
    i++;
  }
  return count;
}

int main() {
  int N;
  cin >> N;

  array<int, 100> A;
  for (auto i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  auto count = bubbleSort(A.data(), N);
  printArray(A.data(), N);
  cout << count << endl;

  return 0;
}

