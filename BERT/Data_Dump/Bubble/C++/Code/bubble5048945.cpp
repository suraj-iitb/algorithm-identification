#include<bits/stdc++.h>
#define NMAX 100

using namespace std;

int main(){
  int N;
  int i,flag=1,cnt=0;
  vector<int> A(NMAX);
  cin >> N;
  for(i=0;i<N;i++) cin >> A[i];
  while(flag){
    flag=0;
    for(i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
        swap(A[i],A[i-1]);
        flag=1;
        cnt++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i<N-1) cout << A[i] << " ";
    else cout << A[i] << endl;
  }
  cout << cnt << endl;
  return 0;
}
