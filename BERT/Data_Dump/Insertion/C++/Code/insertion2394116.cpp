#include <iostream>
#include <algorithm>

using namespace std;
static const int MAX = 200000;

int main(){
  int A[MAX],n;
  int j,v;

  cin >> n;

  for (int i = 0;  i <n; i++){
  cin >> A[i];
}

  for(int i = 0;i<n;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;

  for (int i=0;i<n;i++){
    if(i) cout <<" ";
    cout << A[i];
  }
  cout << endl;

    }
  return 0;
}
