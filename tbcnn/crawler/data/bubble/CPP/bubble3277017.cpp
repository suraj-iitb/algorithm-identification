#include<iostream>
using namespace std;
const int NUMBER=100;

int BubbleSort(int A[],int n){
  int count=0;
  bool flag=1;
  for(int i=0;flag;i++){
    flag=0;
    for(int j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	  swap(A[j],A[j-1]);
	  count++;
	  flag=1;
	}
    }
  }
  return count;
}

int main(){
  int A[NUMBER];
  int n;
  int count;

  cin>>n;

  for(int i=0;i<n;i++){
    cin>>A[i];
  }


  count=BubbleSort(A,n);

  int i;
  for(i=0;i<n-1;i++){
    cout<<A[i]<<' ';
  }
  cout<<A[i]<<endl;

  cout<<count<<endl;

  return 0;
}


  

