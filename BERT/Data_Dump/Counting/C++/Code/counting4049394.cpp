#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<algorithm>

using namespace std;
int main(){

  int n;
  cin >> n;
  int a[n + 1], c[10000], b[n + 1];
  for(int i = 0; i < 10000; i++){
    c[i] = 0;
  }
  for(int i = 1; i < n + 1; i++){
    cin >> a[i];
    c[a[i]]++;
  }

  int sum = 0;
  for(int i = 0; i < 10000; i++){
    sum += c[i];
    c[i] = sum;
  }

  for(int i = n; i >= 1; i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }

  for(int i = 1; i < n; i++){
    cout << b[i] << " ";
  }
  cout << b[n] << endl;



}

