#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> A, int N) {
   for(int i=0; i<N; i++) {
      cout << A.at(i);
      if (i != N-1) cout << " ";
   }
   cout << endl;
} 

void insertionSort(vector<int> A, int N) {
   int i, j, v;
   for (i=0; i<N; i++) {
      v = A.at(i);
      j = i-1;
      while (j >= 0 && A.at(j) > v){
         A.at(j+1) = A.at(j);
         j--;
      }
      A.at(j+1) = v;
      printVector(A, N);
   }
}

int main()
{
   int N;
   cin >> N;

   vector<int> A(N);
   for(int i=0; i<N; i++) cin >> A.at(i);

   insertionSort(A, N);

}
