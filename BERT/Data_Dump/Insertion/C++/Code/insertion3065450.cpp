#include <iostream>
using namespace std;

int N,A[100];

inline void Initial() {
  std::ios::sync_with_stdio(false);
  cout.tie(0); cin.tie(0);
}
inline void Input() {
  cin>>N;
  for (int i=0; i<N; i++) {
    cin>>A[i];
  }
}
inline void Output() {
  for (int i=0; i<N; i++) {
    if (i) {
      cout<<" "<<flush;
    }
    cout<<A[i]<<flush;
  }
  cout<<endl;
}
inline void InsertionSort() {
  Output();
  for (int i=1; i<N; i++) {
    int storage=A[i];
    int j=i-1;
    while (j>=0 and A[j]>storage) {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=storage;
    Output();
  }
}
int main() {
  Initial(),Input(),InsertionSort();
  return 0;
}
