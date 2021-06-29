#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i = 0;i < N;i++){
      cin >> A[i];
  }
  
  int ans = 0;
  
  for(int i = 0;i < N;i++){
      int mib_Num = 101;
      int sort_posi = i;
      for(int j = i;j < N;j++){
          if(mib_Num > A[j]){
              mib_Num = A[j];
              sort_posi = j;
          }
      }
      if(A[i] > A[sort_posi]){
          swap(A[i],A[sort_posi]);
          ans++;
      }
  }
  
  for(int i = 0;i < N;i++){
      if(i != 0) cout << " ";
      cout << A[i];
  }
  cout << endl;
  
  cout << ans << endl;
}

