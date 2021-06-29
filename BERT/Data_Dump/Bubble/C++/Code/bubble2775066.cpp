#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int a[100],N,cnt=0;
  bool flg=1;
  int i=0;
  cin>>N;
  for (int i = 0; i < N; i++) {
    cin>>a[i];
  }
  while (flg) {
    flg=0;
    for(int j=N-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        flg=1;
        cnt++;
      }
    }
    i++;
  }
  for (int i = 0; i < N; i++) {
    if(i!=N-1)  cout << a[i] << ' ';
    else  cout << a[i];
  }
  cout <<'\n'<< cnt << '\n';
  return 0;
}

