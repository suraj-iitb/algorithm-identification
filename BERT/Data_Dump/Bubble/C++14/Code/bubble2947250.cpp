#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  bool flag = true;
  int cnt = 0;
  int dummy;
  
  while(flag){
    
    flag = false;

    for(int i = n-1; i > 0; i--){
      if(a[i] < a[i-1]){
	dummy = a[i];
	a[i]  = a[i-1];
	a[i-1]  = dummy;
	cnt++;
	flag = true;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << a[i]; 
  }

  cout << endl;
  cout << cnt << endl;

  return 0;

}

