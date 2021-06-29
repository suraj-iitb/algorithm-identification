#include <stdio.h>

#include <iostream>
#include <new>

using namespace std;

void displaySequence(int *values, int N) {
  for (int i = 0; i < N; ++i) {
    cout << values[i];
    if (i < N - 1) cout << ' ';
  }
  cout << endl;
}

void insertionSort(int *values, int N) {
  int index, current;

  for (index = 0; index < N; ++index) {
    int targetValue = values[index];
    for (current = index - 1; current >=0 && values[current] > targetValue; --current) {
      values[current + 1] = values[current];
    }
    values[current + 1] = targetValue;

    // Display intermediate sequence:
    displaySequence(values, N);
  }
}

int main() {
  int N;

  scanf("%d", &N);

  int *values = new int[N];

  for (int i = 0; i < N; ++i) {
      scanf("%d", values + i);
  }

  insertionSort(values, N);

  delete[] values;

  return 0;
}
