#include <iostream>
#include <algorithm>

using namespace std;
static const int MAX = 200000;

int main(){
  int A[MAX],n;
  int count = 0;
  bool flag = 1;

  cin >> n;

  for (int i = 0;  i <n; i++){
  cin >> A[i];
}

  for(int i=0;flag ;i++){
    flag = 0;
    for(int j=n-1;j>=i+1 ;j--){
      if(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        flag = 1;
        count++;
      }
    }
  }
  for (int i=0;i<n;i++){
    if(i) cout <<" ";
    cout << A[i];
  }
  cout << endl;

  cout << count;

  cout << endl;
  return 0;
}
