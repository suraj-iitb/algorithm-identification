#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int N, count = 0;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A.at(i);
  for(int i = 0; i < N; i++){
    for(int j = N-1; j > i; j--){
      if(A.at(j) < A.at(j-1)){
        int temp = A.at(j);
        A.at(j) = A.at(j-1);
        A.at(j-1) = temp;
        count++;
      }
    }
  }
  for(int i = 0; i < N; i++){
    cout << A.at(i);
    if(i != N-1) cout << " ";
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
