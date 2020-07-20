#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int v[100];
  int num, n;
  int cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int temp = 0;
  for (int i = 0; i < n; i++){
    for (int j = n - 1; j > i; j--) {
      if(v[j] < v[j - 1]){
        temp = v[j];
        v[j] = v[j - 1];
        v[j - 1] = temp;
        cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << v[i] << (i == n - 1 ? "\n" : " " );
  }
  cout << cnt << endl;
}


