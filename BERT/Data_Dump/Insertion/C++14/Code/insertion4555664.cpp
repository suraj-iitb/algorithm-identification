#include <iostream> // cout, endl, cin
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N - 1; i++){
    cin >> A.at(i);
    cout << A.at(i) << " ";
  }
  cin >> A.at(N - 1);
  cout << A.at(N - 1) << endl;
  
  for(int i = 1; i < N; i++){
    int v = A.at(i);
    int j = i - 1;
    while(j >= 0 && A.at(j) > v){
      A.at(j + 1) = A.at(j);
      j--;
    }
    A.at(j + 1) = v;

    for(int k = 0; k < N - 1; k++){
      cout << A.at(k) << " ";
    }
    cout << A.at(N - 1) << endl;
  }
}

