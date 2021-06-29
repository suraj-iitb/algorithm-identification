#include <bits/stdc++.h>
using namespace std;

void CountingSort(const int* array_in, int* array_out, const int& max_value,
                  const int& n) {
  int array_c[max_value + 1];
  for (int i = 0; i < max_value + 1; i++) {
    array_c[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    array_c[array_in[i]]++;
  }
  for (int i = 1; i < max_value + 1; i++) {
    array_c[i] = array_c[i] + array_c[i - 1];
  }
  for (int i = 0; i < n; i++) {
    array_c[array_in[i]]--;
    array_out[array_c[array_in[i]]] = array_in[i];
  }
}

int main() {
  int n;
  cin >> n;
  int array_in[n];
  int array_out[n];
  int max_value = 0;
  for (int i = 0; i < n; i++) {
    cin >> array_in[i];
    max_value = max(array_in[i], max_value);
  }
  CountingSort(array_in, array_out, max_value, n);
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << array_out[i];
  }
  cout << endl;
  return 0;
}
