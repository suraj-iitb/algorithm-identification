#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int N, cnt = 0;
  
  cin >> N;
  vector<int> v1(N, 0);
  for(int h = 0; h < N; ++h) {
	cin >> v1[h];
  }

  int from = 0, flag = 1;
  while(flag) {
	flag = 0;
	for(int to = N - 1; to >= from + 1; --to) {
	  if(v1[to] < v1[to - 1]) {
		swap(v1[to], v1[to - 1]);
		  cnt++;
		  flag = 1;
	  }
	}
	from++;
  }

  for(int k = 0; k < N; ++k) {
	cout << v1[k];
	cout << (k < N - 1 ? ' ' : '\n');
  }
  cout << cnt << endl;
  return 0;
}
