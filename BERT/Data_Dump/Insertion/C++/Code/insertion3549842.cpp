#include<iostream>
using namespace std;

int  n, v, j;

void insertionSort(int a[]){
  for(int i=1; i<n; i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
    for(int k=0; k<n; k++){
      if(k<n-1) cout << a[k] << " ";
      if(k==n-1) cout << a[k] << endl;
    }
  }
}
 
int main(){
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  for(int k=0; k<n; k++){
    if(k<n-1) cout << a[k] << " ";
    if(k==n-1) cout << a[k] << endl;
  }
  
  insertionSort(a);
  return 0;
}
