#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int selectionSort(vector<int> &a,int n){
  int sw = 0;
  int i,j,minj;
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    swap(a[i],a[minj]);
    if(i!=minj) sw++;
  }
  
  return sw;
}

int main(){
  int n,sw;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  sw = selectionSort(a,n);
  
  rep(i,n){
    if(i!=n-1){
      cout << a[i] << " ";
    }else{
      cout << a[i] << endl;
    }
  }
  
  cout << sw << endl;
  
  return 0;
}
