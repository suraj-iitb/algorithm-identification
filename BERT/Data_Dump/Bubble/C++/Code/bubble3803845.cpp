#include <iostream>
using namespace std;

int bubbleSortAndReturnCount(int[], int);
void displayElements(int[], int);

int main() {
  int n, a[100];
  int count;
  cin >> n;
  for(int i = 0; i < n ; i++) cin >> a[i];
  count = bubbleSortAndReturnCount(a, n);
  displayElements(a, n);
  cout << count << "\n";
  return 0;
}

int bubbleSortAndReturnCount(int a[], int n) {
  int count = 0;
  int flag = 1;
  int headOfSortedData = 0;
  while(flag) {
    flag = 0;
    for(int i = n - 1; i >= headOfSortedData + 1; i--) {
      if(a[i] < a[i-1]) {
        swap(a[i], a[i-1]);
        flag = 1;
        count++;
      }
    }
    headOfSortedData++;
  }
  return count;
}

void displayElements(int a[], int n) {
  cout << a[0];
  for(int i = 1; i < n; i++) cout << " " << a[i];
  cout << "\n";
}
