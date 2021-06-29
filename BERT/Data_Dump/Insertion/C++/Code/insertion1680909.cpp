#include <iostream>
using namespace std;

int main(){
  int N,A[100],key,j;
  cin>>N;
  for(int i=0;i<N;i++)cin>>A[i];
    for(int i=1;i<=N;i++){
      for(int l=0;l<N;l++){
        if(l!=N-1)cout<<A[l]<<" ";
        else cout<<A[l]<<endl;
      }
      key=A[i];
      j=i-1;
      while(j>=0 && A[j]>key){
        A[j+1]=A[j];
        j--;
      }
      A[j+1]=key;
    }
  return 0;
}
