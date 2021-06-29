#include <iostream>
#include <vector>
using namespace std;

void insertion_sort_print(vector<int> a, int n) {

  for (int i = 1; i < n; i++) {

    for (int k=0; k < a.size(); k++) {
      cout << a[k] << (k == n - 1 ? "\n" : " ");
    }

    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;

  }

  for (int k=0; k < a.size(); k++) {
    cout << a[k] << (k == n - 1 ? "\n" : " ");
  }
  
}

int main(void) {
  int n, num;
  vector<int> a;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a.push_back(num);
  }

  insertion_sort_print(a, n);

}
