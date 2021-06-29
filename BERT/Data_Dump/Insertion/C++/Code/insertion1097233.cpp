#include <iostream>
using namespace std;

int main(){

  int n;
  int key;
  int a[110];
  cin >> n;
  for(int i = 0;i < n; i++){
    cin >> a[i];
  }
  int j;
  for(int i = 0;i < n; i++){
    key = a[i];
    j = i-1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    for(int i = 0;i < n;i++){
      if(i == n-1) cout << a[i] <<endl;
      else cout << a[i] << " ";
    }
  }
  
  return 0;
}
