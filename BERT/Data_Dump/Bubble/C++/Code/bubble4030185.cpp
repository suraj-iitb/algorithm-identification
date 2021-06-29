#include <iostream>
using namespace std;

int count = 0;

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int a[], int n){
  bool flag = 1;
  while(flag){
    flag = 0;
    for(int j = n-1; j > 0; --j){
      if(a[j-1] > a[j]){
        swap(&a[j-1], &a[j]);
        flag = 1;
        ++ count;
      }
    }
  }
}

void output(int a[], int n, int count){
  for(int i = 0; i < n-1; ++i) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << count << endl;
}

int main(){
  int n;
  cin >> n;
  int a[100];
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  bubbleSort(a, n);
  output(a, n, count);
  return 0;
}
