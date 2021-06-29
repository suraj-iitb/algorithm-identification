#include <iostream>
using namespace std;
 
int N;
int A[101];
 
void print() {
  for(int i = 1; i <= N; ++i)
    cout << (i!=1?" ":"") << A[i];
  cout << endl;
}
 
int main() {
  cin >> N;
  for(int i = 1; i <= N; ++i) cin >> A[i];
 
  print();
  for(int j = 2; j <= N; ++j) {
    int key = A[j];
    /* insert A[j] into the sorted sequence A[1,....,j-1] */
    int i = j - 1;
    while(i > 0 && A[i] > key) {
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = key;
    print();
  }
  return 0;
}
