#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int n, int a[]) {
  int cnt = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i=n-1;i>0;i--)
      if (a[i] < a[i-1]) {
        swap(a[i], a[i-1]);
        flag = true;
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

  int cnt = bubbleSort(n, a);
  for (int i=0;i<n-1;i++)
    cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << cnt << endl;
  
}

