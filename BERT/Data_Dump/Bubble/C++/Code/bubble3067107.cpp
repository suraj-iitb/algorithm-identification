#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int m = 1;

  cin >> n;

  int a[n];
  int i = 0;
  int cnt = 0;
  int temp = 0;
  
  for(int i=0;i < n;i++){
    cin >> a[i];
  }

  i = 0;
  while(m){
    m = 0;
    
    for(int j=n-1;j > i;j--){
      if( a[j] < a[j-1] ){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	m = 1;
	cnt++;
      }
    }
    i++;
  }
  for(int i=0;i < n;i++){
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

