#include<iostream>
using namespace std;

int main(void){
  int N;//数列の長さ
  int x;
  cin>>N;

  int data[N]={0};
 
  for(int i=0;i<N;i++){
    cin>>x;
    data[i]=x;
  }

  for(int i=0;i<N-1;i++){
    cout<<data[i]<<" ";
  }
  cout<<data[N-1];
  cout<<endl;

  for(int i=1;i<=N-1;i++){
    int v=data[i];
    int j=i-1;

    while(j>=0 && data[j]>v){
      data[j+1]=data[j];
      j--;
    }
    data[j+1]=v;
    
    for(int i=0;i<N-1;i++){
      cout<<data[i]<<" ";
    }
    cout<<data[N-1];
    cout<<endl;
  } 
 
  return 0;
}

