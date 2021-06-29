#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=0;
  int num[100];
  bool b=true;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  while(b){
    b=false;
    for(int i=n-1;i>=1;i--){
      if(num[i]<num[i-1]){
	swap(num[i],num[i-1]);
	b=true;
	cnt++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i==n-1) cout<<num[i];
    else cout<<num[i]<<" ";
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}

