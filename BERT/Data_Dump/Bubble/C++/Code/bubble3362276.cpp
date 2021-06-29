#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, i, ain, flag = 1, tmp, cnt = 0;
  vector<int> a;

  cin >> n;
  for(i = 0;i < n;++i){
    cin >> ain;
    a.push_back(ain);
  }

  while(flag){
    flag = 0;
    for(i = n - 1;i >= 1;--i){
      if(a[i] < a[i-1]){
	tmp = a[i];
	a[i] = a[i-1];
	a[i-1] = tmp;
	flag = 1;
	++cnt;
      }
    }
  }
  for(i = 0; i < n;++i){
    cout << a[i];
    if(i != n-1)cout << " ";
  }
  cout << "\n" <<cnt << endl;
  return 0;
}
