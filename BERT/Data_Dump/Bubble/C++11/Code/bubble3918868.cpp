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

int bubbleSort(int* A, int N){ // N 個の要素を含む 0-オリジンの配列 A
  int flag = 1;
  int count = 0;
  int j;

  while( flag == 1 ){
    flag = 0;
    for( j = N-1; j >= 1; j-- ){
      if (A[j] < A[j-1]){
        swap( A[j], A[j-1] );
        count++;
        flag = 1;
      }
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

  count = bubbleSort( A, N );

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
