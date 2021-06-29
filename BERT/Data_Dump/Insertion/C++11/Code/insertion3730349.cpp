#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>

#define rep(i,n) for(int i=0; i<n;i++)
typedef long long ll;

using namespace std;
const int V = 100005;


int a[100005];
int n;


int main(){
cin >> n;
rep(i,n)cin >> a[i];
rep(i,n){
  if(i == 0){    rep(k,n){
    cout << a[k];
    if(k == n-1){
      break;
    }
    cout<< ' ';
  }
  cout << endl;

 continue;}
  int v = a[i];
  int j = i-1;
  while(j>=0 && a[j] > v){
    a[j+1] = a[j];
    j--;
  }
  a[j+1] = v;
  rep(k,n){
    cout << a[k];
    if(k == n-1){
      break;
    }
    cout<< ' ';
  }
  cout << endl;
}
}

