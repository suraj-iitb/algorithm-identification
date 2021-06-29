#include <iostream>
using namespace std;
int print(int a[],int N){ 
  int i;
  for(i=0;i<N;i++){
    if(i<N-1){
      cout<<a[i]<<" ";
    }
    if(i==N-1){
      cout<<a[i]<<endl;
  }
  }
}
int Insertion(int a[],int N){
  int i,V,j,v;
  for(i=1;i<N;i++){
    v=a[i];
    j=i-1;
    while(j>=0){
      if(a[j]>v){
	V=a[j];
	a[j]=v;
	a[j+1]=V;
      }
      j--;
    }
    print(a,N);
  }
}
int main(){
  int a[1000];
  int N,i;
  cin>>N;
  for(i=0;i<N;i++){
    cin>>a[i];
  }
  for(i=0;i<N;i++){
    if(i<N-1){
    cout<<a[i]<<" ";
    }
    if(i==N-1){
      cout<<a[i]<<endl;
  }
  }
  Insertion(a,N);
  // print(a,N);
  return 0;
  
}
