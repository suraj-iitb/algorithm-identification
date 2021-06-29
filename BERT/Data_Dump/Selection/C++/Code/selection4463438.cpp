#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (1e9)

int main(){
  int n, a[100];
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int counter = 0;

  for(int i = 0; i < n - 1; i++) {
    int minj = i;
    for(int j = i; j < n; j++) {
      if(a[j] < a[minj]) {
        minj = j;
      }
    }
    if(i != minj) {
      swap(a[i], a[minj]);
      counter++;
    }
  }

  cout << a[0];
  for(int i = 1; i < n; i++) {
    cout << " " << a[i];
  }

  cout << endl << counter << endl;

  return 0;
}
