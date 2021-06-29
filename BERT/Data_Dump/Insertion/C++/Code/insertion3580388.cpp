#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int A[110];
  for(int i = 0; i < n; i++){
    cin >> A[i];
    if(i > 0) cout << " ";
    cout << A[i];
    if(i == n - 1) cout << endl;
  }

  

  for(int i = 1; i < n; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    } 

      A[j + 1] = v;

    for(int j = 0; j < n; j++){
      if(j > 0) cout << " ";
      cout << A[j];
    }
    cout << endl;
  }  
  
 }
