#include <iostream>
#include <vector>



using namespace std;

void printarray(vector<int> &a, int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << a[i] << " ";
  }
  cout << a[n - 1] << endl;
}

int main() {
  int n;
  vector<int> a(100);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  printarray(a, n);
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j;
    for (j = i - 1; j >= 0 && a[j] > key; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = key;
    printarray(a, n);
  }
}
