#include<iostream>
using namespace std;
int main(){
  int n; cin>>n;
  int i,j,key;
  int a[n];
  for(int k=0;k<n;k++) cin >> a[k];
  for(int k=0;k<n;k++) cout << a[k] << (k==n-1?'\n':' ');
  for(i=1;i<n;i++){
	key=a[i];
	j=i-1;
	while(j>=0 && a[j] > key){
		a[j+1]=a[j];
		j--;
	}
	a[j+1] = key;
	for(int k=0;k<n;k++) cout << a[k] << (k==n-1?'\n':' ');
  }
  return 0;
}
