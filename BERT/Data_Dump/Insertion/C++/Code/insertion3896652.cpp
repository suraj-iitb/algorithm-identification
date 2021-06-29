#include<iostream>
using namespace std;

void print(int numbers[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << numbers[i];
  }
  cout << endl;
}

int * insertion_sort(int numbers[], int n) {
  for (int i = 1; i < n; i++) {
    int v = numbers[i];
    int j = i - 1;
    while (0 <= j && v < numbers[j]) {
      numbers[j+1] = numbers[j];
      j--;
    }
    numbers[j+1] = v;

    print(numbers, n);
  }

  return numbers;
}

int main() {
  int n;
  cin >> n;

  int cards[n] = {0};

  for (int i = 0; i < n; i++)
    cin >> cards[i];

  print(cards, n);
  insertion_sort(cards, n);

  return 0;
}

