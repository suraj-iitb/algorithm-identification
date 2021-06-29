#include<iostream>

using namespace std;

int main(){
  int num[100]={};
  int count=0;

  cin>>count;
  for(int i=0;i<count;i++){
    cin>>num[i];
  }

  for(int i=0;i<count;i++){
    int tmp=num[i];
    int j=i-1;
    while(j>=0&&num[j]>tmp){
      num[j+1]=num[j];
      j--;
    }
    num[j+1]=tmp;
    for(int k=0;k<count;k++){
      cout<<num[k];
      if(k!=count-1) cout<<" ";
    }
    cout<<endl;
  }
}

