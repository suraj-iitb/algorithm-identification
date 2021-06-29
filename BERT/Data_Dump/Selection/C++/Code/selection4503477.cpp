#include <bits/stdc++.h>
using namespace std;

int main(void) {
  //input
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n;i++) {
    cin >> a.at(i);
  }

  //selectionsort
  int min;
  int count=0;
  for (int i = 0; i < n-1; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
        if (a.at(j) < a.at(min)) {
          min = j;
        }
      }
        if (min != i) {
          swap(a.at(i), a.at(min));
          count++;
      }
    }

  //display
  for (int i = 0; i < n; i++) {
    cout << a.at(i);
    if (i != n-1)
    cout << " ";
  }
  cout << endl;
  cout << count << endl;
}
