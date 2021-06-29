#include <iostream>

using namespace std;

int main() {
  int N;
  int a[100];

  cin >> N;
  for (int i = 0; i <  N; i++) {
    cin >> a[i];
  }

  int tmp, cnt = 0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j = N-1; j > 0; j--) {
      if (a[j] < a[j-1]) {
	cnt++;
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = 1;
      }
    }
  }

  for (int i = 0; i < N-1; i++) {
    cout << a[i] << " ";
  }
  cout << a[N-1] << endl;
  cout << cnt << endl;
  
  return 0;
}
