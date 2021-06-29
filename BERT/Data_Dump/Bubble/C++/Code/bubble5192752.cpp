#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N){
  bool flag=1;
  int i,j;
  int num=0;
  for(i=0;i<N;i++){
    	flag=0;
    	for(j=N-1;j>i;j--){
          if(A[j]<A[j-1]){
            swap(A[j],A[j-1]);
        	num++;
        	flag=1;
      	}
    	}
  	}
  return num;
}

int main(void){
  int N,i,num;
  cin>>N;
  int A[N];
  for(i=0;i<N;i++)cin>>A[i];
  num = bubbleSort(A,N);
  for(i=0;i<N;i++){
    cout<<A[i];
    if(i!=N-1)cout<<" ";
  }
  cout<<endl;
  cout<<num<<endl;

  return 0;
}
