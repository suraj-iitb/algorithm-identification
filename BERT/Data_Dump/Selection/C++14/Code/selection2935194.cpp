#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,mini,count=0;;
  int a[100];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int i=0; i<n; i++){
    mini = i;
    for(int j=i; j<n; j++){
      if(a[j] < a[mini]) mini = j;
      //cout << a[mini] <<  " ";
    }
    //cout << endl;
    if(a[i]>a[mini]){
      swap(a[i],a[mini]);
      count++;
    }
  }
  for(int i=0; i<n; i++){
    if(i>0) cout << " " << a[i];
    else cout << a[i];
  }
  cout << endl;
  cout << count << endl;
  return 0;
}

