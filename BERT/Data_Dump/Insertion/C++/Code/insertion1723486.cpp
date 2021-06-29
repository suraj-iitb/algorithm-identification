#include<iostream>
using namespace std;

int main(){
  int A[100],N,v,j;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>A[i];

  for(int i=0;i<N;i++){
    v=A[i];
    j=i-1;

    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(int i=0;i<N-1;i++)
      cout<<A[i]<<' ';
    cout<<A[N-1]<<endl;
  }
  return 0;
}
