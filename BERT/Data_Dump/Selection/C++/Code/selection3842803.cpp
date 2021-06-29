#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<limits.h>
#include<cmath>
using namespace std;

int main(){

  int n; cin >> n;
  vector<int> A(n); for (int i=0; i<n; i++) cin >> A[i];
  int swapCount = 0;
  for (int i=0; i<n; i++){
    int minj=i;
    for (int j=i; j<n; j++) if (A[j]<A[minj]) minj=j;
    if (i != minj) {
      swap(A[i],A[minj]);
      swapCount++;
    }
  }

  cout << A[0];
  for (int k=1; k<n; k++) cout << " " << A[k];
  cout << endl << swapCount << endl;

  return 0;
}

