#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

int main()
{
  int N, A[MAX], cnt=0;
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];

  //selectsort
  for(int i=0; i<N; i++) {
    int minid = i;
    for(int j=i; j<N; j++) {
      if(A[j] < A[minid]) {
        minid = j;
      }
    }
    if(minid != i) {
      int tmp = A[i];
      A[i] = A[minid];
      A[minid] = tmp;
      cnt++;
    }
  }

  for(int i=0; i<N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}
