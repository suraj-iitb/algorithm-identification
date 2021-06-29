#include <iostream>

using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int p=0;p<N;p++){
    if(p==N-1){
      cout<<A[p]<<endl;
    }else{
      cout<<A[p]<<" ";
    }
  }
  for(int i=1;i<N;i++){
    int v=A[i],j=i-1;
    while(j>=0&&v<A[j]){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(int p=0;p<N;p++){
      if(p==N-1){
        cout<<A[p]<<endl;
      }else{
        cout<<A[p]<<" ";
      }
    }
  }
  return 0;
}

