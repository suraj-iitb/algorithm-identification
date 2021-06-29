#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[100];
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++){
	for(int j=i-1; j>=0; j--){  
	  if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	  else break;
	}
	for(int j=0; j<n; j++){
	  if(j) cout << ' '; //j==0の時実行しない。
	  cout << a[j];
	}
	cout << endl;
  }
  return 0;
}

