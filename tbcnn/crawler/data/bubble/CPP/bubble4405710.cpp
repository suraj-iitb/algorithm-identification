#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

void print(int n,vector<int> a){
  cout << a[0];
  for(int i=1;i<n;i++) cout << " " << a[i];
  cout << endl;
}

int main(){
  int n,count=0;
  bool flag = true;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  while(flag){
    flag = false;
    for(int j=n-1;j>0;j--){
      if(a[j] < a[j-1]) {
	int tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = true;
	count++;
      }
    }
  }
  print(n,a);
  cout << count << endl;
  return 0;
}

