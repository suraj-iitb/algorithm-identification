#include<iostream>
using namespace std;

 int bubbleSort (int A[], int N){
   int sw = 0;
   int i = 0;
  bool flag;
   do {
     flag = 0;
     for (int j = N - 1; j >= i + 1; j--){
       if (A[j] < A[j - 1]){
         swap(A[j], A[j - 1]);
         flag = 1;
         sw++;
       }
     }
     i++;
   } while (flag);
  return sw;
   }

   int main(){
     int N, A[110], ans;
     cin >> N;
     for (int i = 0; i < N; i++){
       cin >> A[i];
     }

     ans = bubbleSort(A,N);
     for (int i = 0; i < N; i++){
       if (i) cout << " ";
       cout << A[i];
     }
     cout << endl;
     cout << ans << endl;
   }

