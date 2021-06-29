#include<iostream>
using namespace std;

int main(){

  int i,j,n,min,swap,count=0;
  int a[100];

  cin >> n;

  for (i=0;i<n;i++){
    cin >> a[i];
  }

  for (i=0;i<n;i++){
    min = i;
    for (j=i;j<n;j++){
      if (a[j]<a[min]){
	min = j;
      }
    }
    if (min > i){
      swap = a[i];a[i] = a[min];a[min] = swap;
	count++;    
    }
  }

  for (i=0;i<n;i++){
    cout << a[i];
    if (i<n-1){
      cout << " ";
    }
  }
  cout << endl << count << endl;

  return 0;

}
