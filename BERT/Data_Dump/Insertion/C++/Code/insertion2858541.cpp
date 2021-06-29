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
  printA(a);
  

  // 1番目から始めるのがキモ!
  // 0番目から始めても，

  // i番目を取り出してvとする．そうするとi番目が1つ空く．
  // 空いたスペースに詰めていって，vより大きいのがあるとそこで挿入してしまう
  for(int i=1;i<N;i++){
    int v = a[i];
    int j = i-1;
    while(j>=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    printA(a);
  }

  return 0;
}

