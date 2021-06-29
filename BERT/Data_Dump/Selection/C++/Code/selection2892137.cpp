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

void trace(int a[], int n){
  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int selectionSort(int A[], int n){
  int minv=0;
  int cnt=0;
  for(int i=0;i<n;i++){
    minv=i;
    for(int j=i;j<n;j++){
      if(A[minv]>A[j]){
        minv=j;
      }
    }
    swap(A[i],A[minv]);
    if(i!=minv) cnt++;
  }
  return cnt;
}

int main (){
  int N;
  cin >> N;
  int B[N];
  int ans=0;
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  ans=selectionSort(B,N);
  trace(B,N);
  cout << ans << endl;
  return 0;
}
