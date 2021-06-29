#include<iostream>
using namespace std;

int main(){
  int n,h[100];
  cin>>n;
  for(int i=0;i<n;i++)cin>>h[i];
  for(int i=1;i<n;i++){
    for(int k=0;k<n;k++){
      cout<<h[k];
      if(k==n-1)cout<<endl;
      else cout<<" ";
    }
    int v=h[i],j=i-1;
    while(j>=0&&h[j]>v){
      h[j+1]=h[j];
      j--;
    }
    h[j+1]=v;
  }
  for(int k=0;k<n;k++){
    cout<<h[k];
    if(k==n-1)cout<<endl;
    else cout<<" ";
  }
  return 0;
}
