#include<stdio.h>
#include<iostream>

using namespace std;

void InsertionSort(int *,int);

int main(){
  int a[100],v,n,i,j,k,l;

  cin >> n;

  for(i=0;i<n;i++)cin >> a[i];

  for (j=0;j<n;j++){
    v = a[j];
    k = j - 1;
    while(k >= 0 && a[k] > v){
      a[k+1] = a[k];
      k--;
      a[k+1] = v;
    }
    for(l=0;l<n-1;l++)cout << a[l] << " ";

    cout << a[l] << endl;
  }

  return 0;
 
}
