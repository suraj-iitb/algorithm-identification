#include <bits/stdc++.h>
using namespace std;

int BubbleSort(vector<int> &A, int N){
  int flag = 1;
  int cnt = 0;
  while(flag == 1){
    flag = 0;
    for(int j = N-1; j >= 1; j--){
      if(A.at(j) < A.at(j-1)){
        swap(A.at(j), A.at(j-1));
        flag = 1;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
	int n;
  cin >> n;
  vector<int> A(n);

  for(int i = 0; i < n; i++){
    cin >> A.at(i);
  }

  int result = BubbleSort(A, n);

  for (size_t i = 0; i < n-1; i++) {
    std::cout << A.at(i) << " ";
  }
  std::cout << A.at(n-1) << '\n';

  std::cout << result << '\n';

}

