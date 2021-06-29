#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pow(x) x*x

void insertionSort(int* A, int N){ // N個の要素を含む0-オリジンの配列A

  int v, i, j;

  for( i = 1; i < N; i++ ){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    REP( i, N ){
      cout << A[i];
      if( i == N - 1 ) break;
      cout <<" ";
    }
    cout << endl;
  }
  
}

int main() {

  int N, i;
  int A[1010];

  cin >> N;

  REP( i, N ){
    cin >> A[i];
  }
    REP( i, N ){
      cout << A[i];
      if( i == N - 1 ) break;
      cout <<" ";
    }
    cout << endl;

  insertionSort( A, N );

}

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/
