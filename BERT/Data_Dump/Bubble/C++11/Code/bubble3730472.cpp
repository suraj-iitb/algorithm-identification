#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i = 1; i<n+1; i++)
typedef long long ll;

using namespace std;
const int V = 100005;
int INF = 1000000000;

int x,y;
int n;
int a[1000];

int main(){
  cin >> n;
  int cnt = 0;
  rep(i,n) cin >> a[i];
  rep(i,n){
    rep(j,n-1){
      if(a[j] > a[j+1]){
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        cnt++;
      }

    }
  }
  rep(i,n){
    cout << a[i];
    if (i == n-1) break;
    cout << ' ';
  }
  cout << endl;
  cout << cnt << endl;
}

