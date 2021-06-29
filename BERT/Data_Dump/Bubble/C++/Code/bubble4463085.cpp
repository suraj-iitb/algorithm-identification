#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (1e9)

int main(){
  int n, flag, counter, a[100];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  flag = 1;
  counter = 0;

  while(flag){
    flag = 0;
    for (int i = n - 1; i > 0; i--){
      if(a[i-1] > a[i]){
        swap(a[i-1], a[i]);
        counter++;
        flag = 1;
      }
    }
  }

  cout << a[0];
  for(int i = 1; i < n; i++){
    cout << " " << a[i];
  }

  cout << endl << counter << endl;

  return 0;
}
