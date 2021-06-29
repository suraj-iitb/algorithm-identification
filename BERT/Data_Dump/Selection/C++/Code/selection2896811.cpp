#include<iostream>
#include<vector>
using namespace std;

void trace(const vector<int>& A) {
    for(int i = 0; i < A.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << A[i];
    }
    cout << endl;
}

int selectionSort(vector<int>& A) {
  int sw = 0;
  int minj;

  for (int i = 0; i < A.size() - 1; i++) {
    minj = i;
    for (int j = i; j < A.size(); j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) {
      sw++;
    }
  }
  return sw;
}

int main(){
  vector<int> A;
  A.reserve(100);

  int N, a;
  cin >> N;
  while(N--){
    cin >> a;
    A.push_back(a);
  }

  int sw = selectionSort(A);

  trace(A);
  cout << sw << endl;

  return 0;
}
