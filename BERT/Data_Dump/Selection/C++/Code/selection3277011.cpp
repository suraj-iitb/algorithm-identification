#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, i, j, ain, minj, tmp, cnt = 0;
  vector<int> a;

  cin >> n;
  for(i = 0;i < n;++i){
    cin >> ain;
    a.push_back(ain);
  }

  for(i = 0;i < n;++i){
    minj = i;
    for(j = i;j < n;++j)
      if(a[j] < a[minj])minj = j;
    if(a[i] != a[minj])++cnt;
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
  }

  
  for(i = 0; i < n;++i){
    cout << a[i];
    if(i != n-1)cout << " ";
  }
  
  cout << "\n" <<cnt << endl;
  return 0;
}
