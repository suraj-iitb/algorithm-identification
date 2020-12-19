#include<bits/stdc++.h>
using namespace std;

int A[10000]={};


void sort(int N){
  for(int i=1;i<N;i++){
    for(int t=i;t>0;t--){
      if(A[t]<A[t-1]){swap(A[t],A[t-1]);}
      else{break;}
    }
    
  for(int t=0;t<N;t++){
    cout<<A[t];
    if(t!=N-1){cout<<" ";}
    else{cout<<endl;}
    }
  }}

int main(){
  int n;
  cin>>n;
  
  for(int i=0;i<n;i++){
    cin>>A[i];
  }

for(int t=0;t<n;t++){
    cout<<A[t];
    if(t!=n-1){cout<<" ";}
    else{cout<<endl;}
    }

 sort(n);
  
  
  return 0;
}

