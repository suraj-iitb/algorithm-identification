#include <iostream>
using namespace std;

int bubbleSort(int A[], int N){
   int sw = 0;
   bool flag = 1;

   for(int i=0; flag; i++){;
      flag = 0;
      for(int j=N-1; j>=i; j--){
         if(A[j]<A[j-1]){
            swap(A[j], A[j-1]);
            flag = 1;
            sw++;
         }
      }
   }
   return sw;
}



int selectionSort(int A[], int N){
   int sw = 0;
   int minj;

   for(int i=0; i<N; i++){
      minj = i;
      for(int j=i; j<N; j++){
         if (A[minj]>A[j])  minj = j;
      }
      swap(A[i], A[minj]);
      if(i!=minj) sw++;
   }
   return sw;
}

int main(){
   int N, i, j, sw;
   int A[100];

   // data input
   cin >> N;
   for(i=0; i<N; i++) cin >> A[i];
  //  N = 6;
  //  A[0] = 5; A[1] = 6; A[2] = 4; A[3] = 2; A[4] = 1; A[5] = 3;

   // execution
   // sw = bubbleSort(A, N);
   sw = selectionSort(A, N);

   // output
   for(i=0; i<N; i++){
      if (i) cout << " ";
      cout << A[i];
   }
   cout << endl;
   cout << sw << endl;

  return 0;
}





