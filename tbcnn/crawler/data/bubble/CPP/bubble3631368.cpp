#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int R[n];
  for(int i=0;i<n;i++){
    cin>>R[i];
  }
  int flag,count=0,copy;
  for(int i=1;i<n;i++){
    flag=i;
    while(1){
      if(flag==0){
        break;
      }else{
        if(R[flag]<R[flag-1]){
          copy=R[flag];
          R[flag]=R[flag-1];
          R[flag-1]=copy;
          count++;
        }else{
          break;
        }
        flag--;
      }
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

