#include<iostream>
using namespace std;

#define N 2000000

int main() {

  int n;
  cin>>n;

  int a[N], max = 0;
  for(int i = 0; i < n; i++) {
    cin>>a[i];
    if(a[i] > max) max = a[i];
  }

  int A[max+1], AA[max+1];
  for(int i = 0; i <= max; i ++) {
    A[i] = 0;
    AA[i] = 0;
  }

  for(int i = 0; i < n; i++) {
    AA[  a[i]  ]++;
  }

  A[0] = AA[0];
  for(int i = 1; i < max+1; i++) {
    A[i] = A[i-1] + AA[i];
  }

  int b[N];
  for(int i = n-1; i >= 0; i--) {
    b[ A[ a[i] ] - 1] = a[i];
    A[ a[i] ]--;
  }

  int i;
  for(i = 0; i < n-1; i++) cout<<b[i]<<' ';
  cout<<b[i]<<endl;

  return 0;
}

