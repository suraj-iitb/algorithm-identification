#include <iostream>
using namespace std;

int bubbleSort(int A[],int n){
  int i,j,c=0,t;
  bool flag=1;
  for(i=0;flag;i++){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]) {
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
	c++;
	flag=1;
      }
    }
  }
  return c;
}

int main(){

  int A[100];
  int n,i,c;

  i=0;
  while(1){
    cin>>n;
    if(1<=n&&n<=100){
      while(1){
	if(n==i) break;
	cin>>A[i];
	if(0<=A[i]&&A[i]<=100) i++;
      }
      break;
    }
  }

  c=bubbleSort(A,n);

  for(i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  cout<<c<<endl;

  return 0;
}

