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
int n;

void trace(int N){
  for(int i=0;i<N;i++){
    cout << a[i];
    if(i!=N-1){
      cout << " ";
    }
  }
  cout << endl;
}

void insertionSort(int N){
  for(int i=1;i<N;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    trace(N);
  }
}

int main (){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  trace(n);
  insertionSort(n);
  return 0;
}
