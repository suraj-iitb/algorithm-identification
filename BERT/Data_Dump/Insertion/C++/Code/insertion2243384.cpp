#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void InsertionSort(int n,int a[]){
  for(int j=0;j<n;j++){
    if(j!=n-1)
      cout << a[j] << " ";
    else
      cout << a[j];
  }
  cout << endl;
  for(int i=1;i<n;i++){
    for(int j=i;j>0;j--){
      if(a[j-1]<a[j])
	break;
      swap(&a[j-1],&a[j]);
    }
    for(int j=0;j<n;j++){
      if(j!=n-1)
	cout << a[j] << " ";
      else
	cout << a[j];
    }
    cout << endl;
  }
}

int main(){

  int n;
  cin >> n;
  int *array=new int[100];
  for(int i=0;i<n;i++)
    cin >> array[i];

  InsertionSort(n,array);

  return 0;
}
