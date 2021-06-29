#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(int A[],int N){ // N 個の要素を含む 0-オリジンの配列 A
  int flag = 1,count=0,k=0; // 逆の隣接要素が存在する
  while(flag){
    flag = 0;
    for(int i=N-1;i>k;i--)
       if (A[i] < A[i-1]){
         swap(A[i],A[i-1]);
         flag = 1;
         count++;
       }
    k++;
    
  }
  cout << A[0];
  for(int i=1;i<N;i++)
    cout<<" "  <<A[i];
  cout << endl<<count<<endl;
  return;
}
  

int main(){
  int n;
  cin >>n;
  int data[100];
  for(int i=0;i<n;i++)
    cin>>data[i];
  bubbleSort(data,n);
  return 0;
}
