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

int bubbleSort(vector<int>& A) {
  int sw = 0;
  bool flag = 1;

  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = A.size() - 1; j >= i + 1; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        flag = 1;
        sw++;
      }
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

  int sw = bubbleSort(A);

  trace(A);
  cout << sw << endl;
}
