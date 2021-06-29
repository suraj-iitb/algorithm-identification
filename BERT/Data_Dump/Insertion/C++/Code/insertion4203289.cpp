#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N){
  for(int i=0; i < N; i++){ 
  if( i > 0 ) cout << ' ';
  cout << A.at(i);
  }
  cout << endl;
}

void insertionSort(vector<int> A, int N){
   for (int i = 1; i < N; i++){
     int v = A.at(i);
     int j = i - 1;
     while (j >= 0 && A.at(j) > v){
       A.at(j+1) = A.at(j);
       j--;
     }
       A.at(j+1) = v;
       trace(A, N);
   }
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i < N; i++) cin >> A.at(i);
    trace(A, N);
    insertionSort(A, N);
}
