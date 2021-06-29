#include <iostream>
#include <vector>

using namespace std;

void printData(vector<int> A, int N) {
   for(int i = 0; i < N; i++) {
      cout << A[i];
      if(i != N - 1) {
         cout << " ";
      } else {
         cout << endl;
      }
   }
}

int bubbleSort(vector<int> A, int N) {
   int swapNum = 0;
   int flag = 1;
   while(flag) {
      flag = 0;
      for(int j = N - 1; j >= 1; j--) {
         if(A[j] < A[j - 1]) {
            swap(A[j], A[j - 1]);
            swapNum ++;
            flag = 1;
         }
      }
   }
   printData(A, N);

   return swapNum;
}

int main () {
   int N;
   cin >> N;

   vector<int> A;

   for(int i = 0; i < N; i++) {
      int r;
      cin >> r;
      A.push_back(r);
   }

   cout << bubbleSort(A, N) << endl;
}
