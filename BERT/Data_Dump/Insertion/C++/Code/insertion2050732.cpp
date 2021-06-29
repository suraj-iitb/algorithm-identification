#include<iostream>
using namespace std;

int main(){

  int i, j, n, v;
  int a[100];

  cin >> n;

  for (i=0;i<n;i++){
    cin >> a[i];
  }

  for (i=1;i<n;i++){

         for (j=0;j<n;j++){
	cout << a[j];
	if (j<n-1){
	  cout << " ";
	}
      }
      cout << endl;

    for (j=0;j<i;j++){
      if (a[j]>a[i]){
	v=a[i];a[i]=a[j];a[j]=v;
      }
    }
 
    }
             for (j=0;j<n;j++){
	cout << a[j];
	if (j<n-1){
	  cout << " ";
	}
      }
      cout << endl;

    return 0;
  }
