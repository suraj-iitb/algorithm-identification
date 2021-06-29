#include <iostream>

int main(int argc, char const *argv[]) {
  using namespace std;
  int n;
  cin >> n;
  int * a = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    cout << a[i] << ' ';
  }
  cout << a[n - 1] << endl;
  for (int i = 1; i < n; i++)
  {
    int key = a[i];
    int j = i - 1;
    while (j >= 0&&a[j] > key)
    {
      a[j + 1] = a[j];
      a[j] = key;
      j--;
    }
    for (int i = 0; i < n - 1; i++)
    {
      cout << a[i] << ' ';
    }
    cout << a[n - 1] << endl;
  }
  delete[] a;
  return 0;
}

