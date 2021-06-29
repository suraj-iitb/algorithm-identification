#include <iostream>
#include <algorithm>
using namespace std;

int selectionSort(int A[],int N){
  int num=0;
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i+1;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    if(minj!=i){
      swap(A[i],A[minj]);
      num++;
    }
  }
  return num;
}

int main(){
  int n;
  cin>>n;
  int a[n];
 for(int i=0;i<n;i++) cin>>a[i];

 int swapNum=selectionSort(a,n);
 for(int i=0;i<n;i++){
   if(i!=0) cout<<' ';
   cout<<a[i];
 }
 cout<<endl<<swapNum<<endl;

 return 0;
}

