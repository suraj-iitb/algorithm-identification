#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int cnt = 0;

  for(int i = 0; i < n; i++){
    int minj = i;

    for(int j = i; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }

    if(i != minj){
      int dummy;
      dummy = a[i];
      a[i] = a[minj];
      a[minj] = dummy;
      cnt++;
    }
  }

  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << a[i];
  }

  cout << endl;
  cout << cnt << endl;

  return 0;

}

