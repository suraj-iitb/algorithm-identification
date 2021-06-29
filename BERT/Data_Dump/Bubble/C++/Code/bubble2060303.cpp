#include <iostream>
using namespace std;

int main(){
  int n,t,c,a[100];
  cin >> n;

  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  
  for(int i = 0;i < n;i++){
    for(int k = n-1;k > i;k--){
      if(a[k] < a[k-1]){
        swap(a[k],a[k-1]);
        c++;
      }
    }
  }
  
  for(int i = 0;i < n;i++){
    cout << a[i];
    if(i != n-1)
      cout << " ";
  }cout << endl << c << endl;
  
  return 0;
}
