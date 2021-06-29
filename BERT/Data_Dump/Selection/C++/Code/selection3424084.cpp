#include <iostream>
using namespace std;

int selectionSort(int a[], int n)
{
  int minj;
  int sw = 0;
  for (int i = 0; i < n; i++) {
    minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj])
	minj = j;
    }
    if (minj != i) {
      swap(a[minj], a[i]);
      sw++;
    }
  }
  return sw;
}

int main()
{
  int a[100], n, sw;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sw = selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    if (i)
      cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}

