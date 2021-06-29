#include <iostream>
using namespace std;

int main(){
  int n, count = 0;
  cin >> n;

  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++)
      if(a[j] < a[min]) min = j;      

    if(min != i){
      int tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
      count++;
    }    
  }

  for(int i = 0; i < n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << count << endl;
  
  return 0;
}
