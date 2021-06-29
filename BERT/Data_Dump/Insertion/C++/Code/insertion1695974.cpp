/* Insertion Sort */

#include <iostream>
using namespace std;

int nums[100];
int N;

void Disp() {
  for (int i = 0; i < N; i++) {
    cout << nums[i];
    if(i != (N - 1)) cout << " ";
  }
  cout << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  Disp();
  for (int i = 1; i < N; i++) {
    int v = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > v) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = v;
    Disp();
  }

  return 0;
}
