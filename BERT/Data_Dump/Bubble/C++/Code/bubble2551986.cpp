#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  bool f=1;
  int ans=0;
  while (f) {
    f=0;
    for (int j=N-1; j>=1; j--) {
      if (A[j]<A[j-1]) {
        int v=A[j-1];
        A[j-1]=A[j];
        A[j]=v;
        ans++;
        f=1;
      }
    }
  }
  for (int i=0; i<N; i++) {
    cout << (i==0?"":" ") << A[i] << flush;
  }
  printf("\n");
  printf("%d\n",ans);
  return 0;
}
