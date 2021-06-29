#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  int count, minj;
  count = 0;
  for(int i=0;i<n;i++){
    minj = i;
    for(int j=i;j<n;j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(minj != i){
      int min = a[minj];
      a[minj] = a[i];
      a[i] = min;
      count++;
      }
  }
  for(int i=0;i<n;i++){
    cout << a[i] << (i==n-1?"\n":" ");
  }
  cout << count << endl;
  return 0;
}

