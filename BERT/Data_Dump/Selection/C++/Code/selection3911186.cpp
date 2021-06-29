#include <bits/stdc++.h>
using namespace std;

int selectionSort(int values[], int n) {
  int switch_count = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (values[j] < values[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(values[i], values[minj]);
      switch_count++;
    }
  }
  return switch_count;
}

int main() {
  int n;
  cin >> n;
  int values[n];

  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  int switch_count = selectionSort(values, n);

  for (int j = 0; j < n - 1; j++) {
    cout << values[j] << " ";
  }
  cout << values[n - 1] << endl;
  cout << switch_count << endl;

}

