#include <iostream>
using namespace std;

int n;
int a[101];

void show_elements(){
  for(int i=0; i<n-1; i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  return ;
}

void solve(){
  show_elements();
  for(int i=1; i < n; i++){
    int key = a[i];
    int j = i-1;
    while (j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    show_elements();
  }
  return ;
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  solve();
  return 0;
}
