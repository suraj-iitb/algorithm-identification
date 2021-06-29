#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

static void printArray(int A[], int N) {
  for (int i = 0; i < N; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl; 
}

static void inputArray(int A[], int num) {
  for (int i = 0; i < num; i++) {
    scanf("%d", &A[i]);
  }
}

static int selectionSort(int A[], int N) {
  int minj, count = 0;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
    	minj = j;
      }
    }
    if (A[i] != A[minj]) {
        swap(A[i], A[minj]);
        count++;
    }
  }
  return count;
}

int main() {
  int N;
  cin >> N;

  array<int, 100> A;
  inputArray(A.data(), N);

  int count = selectionSort(A.data(), N);

  printArray(A.data(), N);
  cout << count << endl;
  
  return 0;
}

