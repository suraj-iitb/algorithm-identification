using namespace std;
#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)



void printAll(vector<int> a){
  rep(i,a.size()-1) cout << a[i] << " ";
  cout << a[a.size()-1] << endl;
}

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N)cin >> a[i];

  int cnt = 0;

  bool flag = true;
  while(flag){
    flag = false;
    for(int i=N-1;i>0;i--){
      if(a[i]<a[i-1]){
        a[i] = a[i]+a[i-1];
        a[i-1] = a[i]-a[i-1];
        a[i] = a[i]-a[i-1];
        cnt++;
        flag = true;
      }
    }
  }
  
  printAll(a);
  cout << cnt << endl;
}
