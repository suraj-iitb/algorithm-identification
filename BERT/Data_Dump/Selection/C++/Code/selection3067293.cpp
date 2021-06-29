#include <iostream>
using namespace std;

int N,A[100],swapcount;

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
inline void SelectionSort() {
  for (int i=0; i<N; i++) {
    int minj=i;
    for (int j=i; j<N; j++) {
      if (A[j]<A[minj]) {
        minj=j;
      }
    }
    swap(A[i],A[minj]);
    if (i!=minj) {
      swapcount++;
    }
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
  cout<<swapcount<<endl;
}
int main() {
  Initial(),Input(),SelectionSort(),Output();
  return 0;
}

