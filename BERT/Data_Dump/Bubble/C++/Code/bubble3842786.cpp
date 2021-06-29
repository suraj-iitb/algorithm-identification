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
  int flag = 1;
  int swapCount = 0;
  while (flag){
    flag = 0;
    for (int j = n-1; j>=1; j--){
      if (A[j-1]>A[j]){
        swap(A[j-1],A[j]);
        flag = 1;
        swapCount++;
      }
    }
  }

  cout << A[0];
  for (int k=1; k<n; k++) cout << " " << A[k];
  cout << endl << swapCount << endl;

  return 0;
}

