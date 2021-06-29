#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector <int> A(N);
  for (int i=0;i<N;i++){
    cin>> A[i];
  }
  int temp;
  int count=0;
  bool flag=1;
  while(flag){
    flag=0;
    for (int j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
        temp=A[j-1];
        A[j-1]=A[j];
        A[j]=temp;
        count++;
        flag=1;
      }
    }
  }
  for (int i=0;i<N-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[N-1]<<endl;
  cout<<count<<endl;
  return 0;
}


        

