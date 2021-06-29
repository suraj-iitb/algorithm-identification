#include <iostream>
#include <cstdio>

using namespace std;

int A[101], n;

void print () {
  for (int i = 0; i < n; i++)
    if (i == n - 1)
      cout << A[i] << endl;
    else
      cout << A[i] << " ";
}

void insertionSort () {
  int temp, j;
  
  for (int i = 1; i < n; i++) {
    print();

    temp = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > temp) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = temp;
  }
}

int main () {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  insertionSort();
  print();

  return 0;
}

