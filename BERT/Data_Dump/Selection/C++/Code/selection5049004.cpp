#include<bits/stdc++.h>
#define NMAX 100

using namespace std;

int main(){
  int N;
  int i,cnt=0,minj;
  vector<int> A(NMAX);
  cin >> N;
  for(i=0;i<N;i++) cin >> A[i];
  for(i=0;i<N;i++){
    minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    swap(A[i],A[minj]);
    if(minj!=i) cnt++;
  }
  for(i=0;i<N;i++){
    if(i<N-1) cout << A[i] << " ";
    else cout << A[i] << endl;
  }
  cout << cnt << endl;
  return 0;
}
