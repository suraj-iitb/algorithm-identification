#include<iostream>
#include<vector>
using namespace std;

int bubbleSort(vector<int>& A, int N){
  int sw=0;
 // core code of bubbleSort
  for(int i = 0 ; i < N - 1 ; i++){// After the last smallest N - 1 elements are in their right place, the numbers are sorted!
      for (int j = N - 1 ; j >= i + 1; j --){//start from the last element！
          if (A[j] < A[j-1]){
              swap(A[j], A[j-1]);
              sw++;
          }
      }
  }
 // core code of bubbleSort!
  for(int k = 0; k < N; k++){
   if (k == (N-1)) cout<<A[k]<<endl;
   else cout<<A[k]<<" ";
  }
  return sw;
}

int main(){
 int N;
 vector<int> A(100);
 cin>>N;
 for(int i =0; i <N; i++) cin>>A[i];

 int sw = bubbleSort(A,N);
 cout<<sw<<endl;
}
