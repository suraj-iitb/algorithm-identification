#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  int flag = 1;
  int count = 0;
  while (flag){
    flag = 0;
    for (int i = N-1; i > 0; i--){
      if (A.at(i) < A.at(i-1)){
        using std::swap;
        swap (A.at(i-1), A.at(i));
        flag = 1;
        count++;
      }
    }
  }
  for (int j=0; j < N ; j++) cout << A.at(j) << (j == N-1?'\n':' ');
  cout << count << endl;
}
