#include <iostream>
using namespace std;

int main(void){
  int n, a[100];
  int swpCnt=0;
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=n-1; i>=0; i--){
    int swapped = 0;
    for (int j=0; j<i; j++){
      if (a[j]>a[j+1]){
        int tmp;
        tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;
        swapped = 1;
        swpCnt++;
      }
    }
    if (swapped==0) break;
  }
  for (int i=0; i<n-1; i++) cout << a[i] << " ";
  cout << a[n-1] << endl;
  cout << swpCnt << endl;
  return 0;
}

