#include<iostream>
using namespace std;

main(){

  int i,j,N,array[100],key;

  cin>>N;
  for(i=0; i<N; i++)cin>>array[i];

  for(i=0; i<N; i++){
    key=array[i];
    j=i-1;
    while(j>=0  && array[j]>key){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=key;
    for(j=0; j<N; j++){
      if(j==N-1){
        cout<<array[j]<<endl;
        break;
      }
      cout<<array[j]<<" ";
    }
  }

}
