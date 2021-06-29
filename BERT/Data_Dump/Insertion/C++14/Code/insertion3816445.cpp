#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &a, int i);
void output(vector<int> &a);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  output(a);
  for (i = 1; i < n; i++) {
    insertion_sort(a, i);
    output(a);
  }
  return 0;
}

void insertion_sort(vector<int> &a, int i) {
  int v = a[i];
  int j = i - 1;
  while (j >= 0 && a[j] > v) {
    a[j + 1] = a[j];
    j--;
  }
  a[j + 1] = v;
}

void output(vector<int> &a) {
  int i;
  for (i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i != a.size() - 1) {
      cout << ' ';
    }
  }
  cout << endl;
}

