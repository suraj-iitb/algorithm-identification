#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
  int A[110], N, cnt=0;
  cin>>N;
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<N;i++){
    for(int j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	int v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	cnt += 1;
      }
    }
  }
  for(int i=0;i<N-1;i++) cout<<A[i]<<" ";
  cout<<A[N-1]<<endl;
  cout<<cnt<<endl;
  return 0;
}

