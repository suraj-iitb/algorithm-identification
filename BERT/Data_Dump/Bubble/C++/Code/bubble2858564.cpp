#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define printA(arr) for(int i = 0; i < SZ(arr); i++){cout << arr[i];if (i==SZ(arr)-1){cout<<endl;}else{cout << " ";}}
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<int> a;

  REP(i,N){
    int num;
    cin >> num;
    a.push_back(num);
  }

  int cnt = 0;
  // iより左はソート済み．
  // i+1より左を隣同士で入れ替えていく．
  for(int i=0;i<N;i++){
    for(int j=i-1;j>=0;j--){
      if (a[j]>a[j+1]){
        int tmp = a[j+1];
        a[j+1] = a[j];
        a[j] = tmp;
        cnt++;
      }
    }
  }
  printA(a);
  cout << cnt << endl;

  return 0;
}

