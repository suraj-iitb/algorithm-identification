#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cmath>
#include <math.h>
using namespace std;

int isprime(int x){
  if (x<2) return 0;
  if (x==2) return 1;
  if (x%2==0) return 0;
  for (int i=3;i<=sqrt(x);i+=2){
    if (x%i==0) return 0;
  }
  return 1;
}

int main(){
  int n,cnt;
  int a[100];
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  for (int i=0;i<n;i++) {
    for (int j=n-1;0<j;j--) {
      if (a[j]<a[j-1]) {
        swap(a[j],a[j-1]);
        cnt++;
      }
    }
  }
  for (int i=0;i<n;i++) {
    if (i==(n-1)) {
      cout << a[i] << endl;
    } else { cout << a[i] << " "; }
  }
  cout << cnt <<endl;
}

