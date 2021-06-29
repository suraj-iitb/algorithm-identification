#include <iostream>
#include <vector>

using namespace std;

void printData(vector<int> Data, int N) {
   for(int i = 0; i < N; i++) {
      cout << Data[i];
      if(i != N - 1) {
         cout << " ";
      }
   }

   cout << endl;
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
   
   printData(A, N);
   for(int i = 1; i <= N - 1; i++) {
      int v = A[i];
      int j = i - 1;
      while(j>= 0 && A[j] > v) {
         A[j + 1] = A[j];
         j --;
      }
      A[j + 1] = v;
      printData(A, N);
   }
}



   
      

