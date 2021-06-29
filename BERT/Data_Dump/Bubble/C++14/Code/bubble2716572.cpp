#include <iostream>
#include <algorithm>
using namespace std;

int bubblesort(int A[], int N){
   bool flag = 1;
   int count = 0;
   while(flag){
      flag = 0;
      for(int i=N-1; i>0; i--){
         if(A[i] < A[i-1]){
            int tmp = A[i];
            A[i] = A[i-1];
            A[i-1] = tmp;
            flag = 1;
            count++;
         }
      }
   }
   return count;
}

int main()
{
   int A[100];
   int N;
   cin >> N;
   for(int i=0; i<N; i++) cin >> A[i];
   int n = bubblesort(A, N);
   for(int i=0; i<N; i++){
      if(i != N-1) cout << A[i] << " ";
      else cout << A[i] << endl;
   }
   cout << n << endl;
}
