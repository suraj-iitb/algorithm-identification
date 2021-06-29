#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int R[n];
  for(int i=0;i<n;i++){
    cin>>R[i];
  }
  int count=0,copy;
  for (int i=0;i<n;i++){
    int minA=i;
    for(int j=i;j<n;j++){
      if(R[j]<R[minA]){
        minA=j;
      }
    }
    if(i!=minA){
      copy=R[i];
      R[i]=R[minA];
      R[minA]=copy;
      count++;
    }
  }
  for(int i=0;i<n;i++){
    if(i==n-1){
        cout<<R[i]<<endl<<count<<endl;
    }else{
        cout<<R[i]<<" ";
    }
  }
  return 0;
}

