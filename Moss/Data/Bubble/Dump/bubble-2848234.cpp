#include<bits/stdc++.h>
using namespace std;

int sort(int *a,int n){
  int count=0;
  bool j=true;
  while(j){
    j=false;
    for(int i=1;i<n;i++){
    if(*(a+i-1)>*(a+i)){j=true; swap(*(a+i-1),*(a+i)); count++;}
  }}
  return count;
}


int main(){
  int n;
  cin>>n;
  int a[100000];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int c=sort(a,n);
  for(int i=0;i<n;i++){
    cout<<a[i];
    if(i!=n-1){cout<<" ";}
  }
  cout<<endl<<c<<endl;
  
  return 0;
}

