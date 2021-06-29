#include <iostream>
using namespace std;

int main() {
  int N;
  cin>>N;
  int A[N];
  for (int i=0; i<N; i++) {
    cin>>A[i];
  }
  int sw=0;
  bool f=true;
  for (int i=0; f; i++) {
    f=false;
    for (int j=N-1; j>=i+1; j--) {
      if (A[j]<A[j-1]) {
        swap(A[j],A[j-1]);
        f=true;
        sw++;
      }
    }
  }
  for (int i=0; i<N; i++) {
    cout<<(i==0?"":" ")<<A[i]<<flush;
  }
  cout<<endl;
  cout<<sw<<endl;
  return 0;
}

