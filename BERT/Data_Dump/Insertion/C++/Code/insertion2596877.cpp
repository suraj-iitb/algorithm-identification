#include<bits/stdc++.h>

using namespace std;
 
int main () {
  int n;
  cin >> n;
  int a [n];
  int i, j, k, temp;
  for (i = 0; i < n; i++) {
    cin >> a [i];
  }
  cout << a [0];
  for (k = 1; k < n; k++) {
      cout << " " << a [k];
  }
  cout << endl;

  for (i = 1; i < n; i++) {
    temp = a [i];
    j = i - 1;
    while (j >= 0 && a [j] > temp) {
      a [j + 1] = a [j];
      j--;
    }
    a [j + 1] = temp;

  cout << a [0];
  for (k = 1; k < n; k++) {
      cout << " " << a [k];
  }
  cout << endl;
  }

  return 0;
}
