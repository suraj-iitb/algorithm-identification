#include<iostream>
#include<vector>
#include<cmath>
#define _GLIBCXX_DEBUG
using namespace std;

void insertionSort(vector<int> A,int N)
{
  for(int i=1;i<N;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(int k=0;k<N;k++){
      if(k!=N-1)
        cout<<A[k]<<" ";
      else cout<<A[k];
    }
    cout<<endl;
  }
}
int main()
{
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int k=0;k<N;k++){
      if(k!=N-1)
        cout<<A[k]<<" ";
      else cout<<A[k];
    }
    cout<<endl;
  insertionSort(A,N);
  return 0;
}

