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
inline void BubbleSort() {
  bool flag=true;
  while (flag) {
    flag=false;
    for (int j=N-1; j>=1; j--) {
      if (A[j]<A[j-1]) {
        swap(A[j],A[j-1]);
        flag=true;
        swapcount++;
      }
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
  Initial(),Input(),BubbleSort(),Output();
  return 0;
}


