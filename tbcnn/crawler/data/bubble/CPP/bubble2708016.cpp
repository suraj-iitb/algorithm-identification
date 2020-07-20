#include <iostream>
using namespace std;

int bubbleSort(int, int*);
int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  int sorted = bubbleSort(n, a);
  for(int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1];
  cout << endl << sorted << endl;

  return 0;
}

int bubbleSort(int n, int* a){
  int count=0;
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(a[j]>a[j+1]){
        int p = a[j];
        a[j] = a[j+1];
        a[j+1] = p;
        count++;
      }
    }
  }
  return count;
}

