#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> A;
  A.reserve(100);

  int N, a;
  cin >> N;
  while(N--){
    cin >> a;
    A.push_back(a);
  }

  // Do insertion sort
  for(int i = 0; i < A.size(); i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    // Print current
    for(int k = 0; k < A.size(); k++) {
      cout << (k == 0 ? "" : " ") << A[k];
    }
    cout << endl;
  }
}
