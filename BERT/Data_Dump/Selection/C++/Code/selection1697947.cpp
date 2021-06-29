/* Selection Sort */

#include <iostream>
using namespace std;

inline void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int main() {
  int array[100];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> array[i];

  int cnt = 0;
  for(int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i; j < n; j++) if(array[j] < array[mini]) mini = j;
    if (mini != i) { cnt++; swap(&array[mini], &array[i]); }
  }

  for (int i = 0; i < n; i++) { cout << array[i]; if (i < n - 1) cout << " "; }
  cout << endl << cnt << endl; 

  return 0;
}
