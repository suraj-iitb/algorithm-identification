#include <iostream>
using namespace std;

#define MAX 101
int A[MAX];

int main(){
  int i, j, n, cnt, swap;
  bool flag = 1;
  cin >> n;
  for (i = 0; i < n; i++)    cin >> A[i];
  for (i = 0; flag; i++){
    flag = 0;
    for (j = n - 1; j >= i + 1; j--){
      if (A[j] < A[j - 1]){
        cnt++;
        swap = A[j];
        A[j] = A[j - 1];
        A[j - 1] = swap;
        flag = 1;
      }
    }
  }


  cout << A[0];
  for (i = 1; i < n; i++) cout << " " << A[i];
  cout << "\n";
  cout << cnt << "\n";
  return 0;

}
