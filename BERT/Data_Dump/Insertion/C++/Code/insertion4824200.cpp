#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &A, int N){
   for (int i = 0; i < N; i++){
      if (i != N - 1)
      	cout << A.at(i) << " ";
      else
        cout << A.at(i) << endl;
    }
}

void insertionSort(vector<int> &A, int N){
  int v, j;
  for (int i = 1; i < N; i++){
    v = A.at(i);
    j = i - 1;
    while (j >= 0 && A.at(j) > v){
      A.at(j + 1) = A.at(j);
      j--;
    }
    A.at(j + 1) = v;
    
    printArray(A, N);
  }
}

using namespace std;

int main(void){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  printArray(A, N);
  insertionSort(A, N);
  return 0;
}
