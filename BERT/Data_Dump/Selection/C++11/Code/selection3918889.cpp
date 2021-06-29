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

int selectionSort(int* A, int N){ // N 個の要素を含む 0-オリジンの配列 A
  int count = 0;
  int i, j;
  int minj;

  for( i = 0; i <= N-1; i++){
    minj = i;
    for( j = i; j <= N-1; j++ ){
      if( A[j] < A[minj] ){
        minj = j;
      }
    }
    if( i != minj ){
      swap( A[i], A[minj] );
      count++;
    }
  }

  return count;
}

int main() {

  int N, A[200];
  int count;

  cin >> N;

  REP(i, N){
    cin >> A[i];    
  }

  count = selectionSort( A, N );

  REP(i, N){
    cout << A[i];
    if( i != N-1 ){
      cout << " ";
    }    
  }
  cout << endl;
  cout << count << endl;

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
