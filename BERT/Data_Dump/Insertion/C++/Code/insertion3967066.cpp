#include<bits/stdc++.h>
using namespace std;
int N;
vector<int>A;
void out(){
  for(int i=0;i<N;i++)cout<<A[i]<<(i!=N-1?" ":"\n");
}
void insertionSort(){
  for(int i=1;i<N;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    out();
  }
}
int main(void){
  cin>>N;
  A.resize(N);
  for(int i=0;i<N;i++)cin>>A[i];
  out();
  insertionSort();
  return 0;
}

