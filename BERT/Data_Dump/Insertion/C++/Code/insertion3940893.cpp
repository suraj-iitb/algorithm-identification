#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,v;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  for(int i=0;i<n;i++){
    cout << a[i];
    if(i==n-1)
      cout << endl;
    else
      cout << " ";
  }
  
  for(int i=1;i<n;i++){
    int j;
    v = a[i];
    j = i-1;
    while(j>=0&&a[j]>v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1]=v;
    
    for(int i=0;i<n;i++){
      cout << a[i];
      if(i==n-1)
      cout << endl;
    else
      cout << " ";
    }
  }
  
  return 0;
}

