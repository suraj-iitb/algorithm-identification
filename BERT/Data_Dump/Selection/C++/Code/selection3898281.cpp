#include<iostream>
using namespace std;

void print(int numbers[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << numbers[i];
  }
  cout << endl;
}

int selection_sort(int numbers[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    int minj = i;

    for (int j = i; j < n; j++)
      if (numbers[j] < numbers[minj])
        minj = j;

    if (i != minj) {
      count++;
      swap(numbers[i], numbers[minj]);
    }
  }

  print(numbers, n);

  return count;
}

int main() {
  int n;
  cin >> n;

  int numbers[n] = {0};

  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  int count = selection_sort(numbers, n);
  cout << count << endl;

  return 0;
}

