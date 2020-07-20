/* Bubble Sort */
#include <iostream>
using namespace std;

inline void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int main() {
  int cnt = 0;
  int n;
  int nums[100] = {};
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(&nums[j], &nums[j + 1]);
        cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << nums[i];
    if (i != n - 1) cout << " ";
  }
  cout << endl << cnt << endl;
}
