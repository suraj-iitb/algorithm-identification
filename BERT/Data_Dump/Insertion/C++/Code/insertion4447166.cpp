#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &A,int N){
  int v,j;
  for(int l=0;l<N;l++){
      if(l==N-1)
        cout<<A.at(l);
      else
        cout<<A.at(l)<<" ";
    }
    cout<<endl;
  for(int i=1;i<N;i++){
    v=A.at(i);
    j=i-1;
    while(j>=0&&A.at(j)>v){
      A.at(j+1)=A.at(j);
      j--;
    }
    A.at(j+1)=v;
    for(int l=0;l<N;l++){
      if(l==N-1)
        cout<<A.at(l);
      else
        cout<<A.at(l)<<" ";
    }
    cout<<endl;
  }
  
}

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  insertionsort(A,N);
  
}

