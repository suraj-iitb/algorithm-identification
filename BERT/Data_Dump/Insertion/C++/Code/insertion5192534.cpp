#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N,i,j,k,key;
  cin>>N;
  vector<int> vec(N);
  for(i=0;i<N;i++)cin>>vec[i];
  for(k=0;k<N;k++){
      cout<<vec[k];
      if(k!=N-1){
        cout<<" "; 
      }else{
        cout<<endl;
      }
    }
  
  for(i=1;i<N;i++){
    key=vec[i];
    j=i-1;
    while(j>=0 and vec[j]>key){
      vec[j+1]=vec[j];
      j--;
    }
    vec[j+1]=key;
    for(k=0;k<N;k++){
      cout<<vec[k];
      if(k!=N-1){
        cout<<" "; 
      }else{
        cout<<endl;
      }
    }
    
  }
  return 0;
}
