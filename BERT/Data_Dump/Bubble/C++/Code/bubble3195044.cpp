#include <iostream>
using namespace std;

void swap(int* px, int* py){
  int z;
  z = *px;
  *px = *py;
  *py = z;
}

void output(int a[], int n){
  for(int i=0; i<n; i++){
    cout << a[i] << (i!=n-1 ? " ": "");
  }
  cout << endl;
}

void BubbleSort(int a[], int n){
  bool flag = 1;
  int count = 0;
  while(flag){
    flag = 0;
    for(int i=n-1; i>0; i--){
      if(a[i]<a[i-1]){
        swap(&a[i], &a[i-1]);
        flag = 1;
        count++;
      }
    }
  }
  output(a, n);
  cout << count << endl;
}

int main(void){
  int n;
  cin >> n;

  int a[n];
  for(int i; i<n; i++){
    cin >> a[i];
  }

  BubbleSort(a, n);

  return 0;
}

