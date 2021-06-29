#include <iostream>

using namespace std;

int main()
{
  int n;
  int i=0, j=0, v;
  cin >> n;
  int a[n];
  for(i = 0; i < n; i++) cin >> a[i];
  for(i = 0; i < n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  //?????????
  for(i=1; i<n; i++){
    v = a[i];
    j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(j=0; j<n-1; j++) cout << a[j] << " ";
    cout << a[n-1] << endl;

  }

  return 0; 
    
}
