#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<list>
#include<set>
using namespace std;
//配列の要素を順番に出力
void trace(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0){
      printf(" ") ; //隣接する要素の間に一つの空白を出力
    }
    cout << a[i];
  }
  printf("\n");
}
void insertionSort(int a[],int n){
  int j,i,v;
  for(int i=1;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    trace(a,n);
  }
}
int main(){
  int n,i,j;
  int a[100];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  trace(a,n);
  insertionSort(a,n);

  return 0;
}

