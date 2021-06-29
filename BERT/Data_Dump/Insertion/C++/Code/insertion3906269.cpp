#include <iostream>

using namespace std;

void prt(int a[], int n);
int main(){

  int n;
  cin >> n;

  int a[n];

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  prt(a, n);

  for(int i = 1; i < n; i++){
    int v = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    } 
    a[j+1] = v;
    prt(a, n);
  }

  return 0;
}
void prt(int a[], int n){

  for(int i = 0; i < n-1; i++){
    cout << a[i] << ' ';
  }

  cout << a[n-1] << '\n';
}
    

