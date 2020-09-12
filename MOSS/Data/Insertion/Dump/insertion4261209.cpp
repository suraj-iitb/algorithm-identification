#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  for (int i = 0; i < N; i++){
    int j = i;
    while (1){
      if (j == 0){
        break;
      }
      if (a[j] < a[j - 1]){
        swap(a[j], a[j - 1]);
      } else {
        break;
      }
      j--;
    }
    for (int j = 0; j < N; j++){
      cout << a[j];
      if (j < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
