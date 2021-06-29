#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector <int> a(N);
  for (int i=0;i<N;i++){
    cin>>a[i];
  }
    for(int k=0;k<N;k++){
      if(k<N-1){
        cout<<a[k]<<" ";
      }
      else cout<<a[k]<<endl;
    }
  for (int i=1;i<N;i++){
    int v=a[i];
    int j=i-1;
    while((j>=0)&&(a[j]>v)){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(int k=0;k<N;k++){
      if(k<N-1){
        cout<<a[k]<<" ";
      }
      else cout<<a[k]<<endl;
    }
  }
  return 0;
}

  


  
  
  

  

  


  
  
  

  
