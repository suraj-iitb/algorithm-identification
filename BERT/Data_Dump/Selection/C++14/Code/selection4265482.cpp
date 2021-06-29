#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  bool flag=0;
  int count=0;
  vector <int> A(N);
  for (int i=0;i<N;i++){
    cin>> A[i];
  }
  for(int i=0;i<N;i++){
    int minj=i;
    flag=0;
    for (int j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj =j;
        flag=1;
      }

      }
          if(flag){
        count++;
        flag=0;
    }
    int temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
  }

  
  for (int i=0;i<N-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[N-1]<<endl;
  cout<<count<<endl;
  return 0;
}


        

