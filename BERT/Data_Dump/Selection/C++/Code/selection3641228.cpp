#include <bits/stdc++.h>
using namespace std;

int selectionSort(int n, int a[]) {
  int cnt = 0;
  for (int i=0;i<n;i++) {
    int minj = i;
    for (int j=i;j<n;j++)
      if (a[j] < a[minj])
        minj = j;
    if (i != minj) {
      swap(a[i], a[minj]);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n, a[100];
  cin >> n;
  for (int i=0;i<n;i++)
    cin >> a[i];

  int cnt = selectionSort(n, a);
  for (int i=0;i<n-1;i++)
    cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << cnt << endl;
}

