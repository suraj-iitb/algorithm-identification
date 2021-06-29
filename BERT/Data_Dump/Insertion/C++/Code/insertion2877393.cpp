#include <iostream>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
void insertionSort(int A[], int N){// N個の要素を含む0-オリジンの配列A
   int j,v;
   //print input array
   for(int k = 0; k<N; k++){
     if(k!=N-1)cout<<A[k]<<' ';
     else cout<<A[k]<<endl;
   }
   //sort
   for(int i=1;i<N;i++){
     v = A[i];
     j = i - 1;
     while (j >= 0 && A[j] > v){
       A[j+1] = A[j];
       j--;
     }
      A[j+1] = v;

      //print previous array
     for(int k = 0; k<N; k++){
       if(k!=N-1)cout<<A[k]<<' ';
       else cout<<A[k]<<endl;
     }
   }

}


int main(){
  int N;
  cin >> N;
  int A[N];
  for(int i = 0;i < N;i++) cin >> A[i];

  insertionSort(A,N);
  return 0;
}

