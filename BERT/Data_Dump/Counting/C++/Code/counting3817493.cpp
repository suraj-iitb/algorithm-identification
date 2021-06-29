#include<bits/stdc++.h>
using namespace std;
int b[100000000];
int main(){
  int a;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b[i];
  }
  sort(b,b+a);
  for(int i=0;i<a;i++){
    cout<<b[i];
    if(i!=a-1) cout<<" ";
  }
  cout<<"\n";
}

