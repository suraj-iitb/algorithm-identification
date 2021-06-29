#include<bits/stdc++.h>
#define N 100
using namespace std;

int main(){
  int n;
  int i,j,k,key;
  int a[N];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=1;i<n;i++){
    for(k=0;k<n;k++){
      if(k!=n-1) cout << a[k] << " ";
      else cout << a[k] << endl;
    }
    key=a[i];
    j=i-1;
    while(j >= 0 && a[j] > key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1] = key;
  }
  for(i=0;i<n;i++){
    if(i!=n-1) cout << a[i] << " ";
    else cout << a[i] << endl;
  }
  return 0;
}

  

