#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int A[100];
int n;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int j=0;j<n;j++){
    int key=A[j];
    int i=j-1;
    while(0<=i && key<A[i]){
      A[i+1]=A[i];
      i=i-1;
    }
    A[i+1]=key;
    for(int k=0;k<n;k++){
      cout<<A[k];
      if(k!=n-1){
        cout<<" ";
      }else{
        cout<<endl;
      }
    }
  }
}
