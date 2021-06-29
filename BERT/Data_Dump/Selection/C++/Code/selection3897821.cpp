#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int A[101], n, cnt = 0;

void print () {
  for (int i = 0; i < n; i++)
    if (i == n - 1)
      cout << A[i] << endl;
    else
      cout << A[i] << " ";
}

void SelectionSort () {
  int minj;

  for (int i = 0; i < n; i++) {
    minj = i;

    for (int j = i; j < n; j++)
      if (A[j] < A[minj])
        minj = j;

    if (i != minj)
      cnt++;
    
    swap(A[i], A[minj]);
  }
}

int main () {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> A[i];

  SelectionSort();
  print();
  cout << cnt << endl;

  return 0;
}

