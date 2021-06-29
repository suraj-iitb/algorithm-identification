#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;
map <int ,int> mpa,mpb;

int a[100];

void trace(int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int bubbleSort(int n){
  int cnt=0;
  int flag=1;
  int v=0;
  while(flag){
    int i=0;
    flag=0;
    for(int j=n-1;i+1<=j;j--){
      if(a[j]<a[j-1]){
        v=a[j];
        a[j]=a[j-1];
        a[j-1]=v;
        cnt++;
        flag=1;
      }
    }
    i++;
  }
  return cnt;
}

int main (){
  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  int ans = bubbleSort(N);
  trace(N);
  cout << ans << endl;
  return 0;
}
