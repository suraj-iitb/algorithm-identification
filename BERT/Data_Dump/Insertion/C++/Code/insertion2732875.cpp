#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& A, int N){
 for(int k = 0; k < N; k++){
   if (k == (N-1)) cout<<A[k]<<endl;
   else cout<<A[k]<<" ";
 }
 for(int i = 1; i < N; i++){
  int v = A[i];
  int j = i - 1;
  while(j>= 0 && A[j]>v){
   A[j+1] = A[j];
   j--;
}
  A[j+1] = v;

  for(int k = 0; k < N; k++){
   if (k == (N-1)) cout<<A[k]<<endl;
   else cout<<A[k]<<" ";
}
}
}

int main(){
 int N;
 vector<int> A(100);
 cin>>N;
 for(int i =0; i <N; i++) cin>>A[i];

 insertionSort(A,N);
}
