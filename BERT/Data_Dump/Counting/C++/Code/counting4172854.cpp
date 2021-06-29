#include<bits/stdc++.h>
using namespace std;
void counting_sort(vector<int>&A,vector<int>&B,int k,int N){
  vector<int>C(k+1);
  for(int i=0;i<N;i++)C[A[i]]++;
  for(int i=1;i<=k;i++)C[i]=C[i]+C[i-1];
  for(int i=N-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }
}
int main(void){
  int N;
  cin>>N;
  vector<int>A(N),B(N);
  int k=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    k=max(A[i],k);
  }
  counting_sort(A,B,k,N);
  for(int i=0;i<N;i++)cout<<B[i]<<" \n"[i==N-1];
  return 0;
}

