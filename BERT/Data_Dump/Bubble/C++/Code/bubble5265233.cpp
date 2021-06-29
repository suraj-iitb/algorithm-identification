#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(int A[],int N){
  bool flag=1;
  int sum=0;
  while(flag){
    flag=0;
    for(int j=0;j<N-1;j++){
      if(A[j]>A[j+1]){
        swap(A[j],A[j+1]);
        sum++;
        flag=1;
      }
    }
  }
  return sum;
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];

  int swapNum=bubbleSort(a,n);
  for(int i=0;i<n;i++){
    if(i!=0) cout<<' ';
    cout<<a[i];
  }
  cout<<endl<<swapNum<<endl;

  return 0;
}

