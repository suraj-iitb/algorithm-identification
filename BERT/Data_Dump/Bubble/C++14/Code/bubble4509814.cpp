#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 1; j <= (int)(m); j++)

int bSort(int a[], int n){
int sw = 0;
bool flag = 1;
for (int i = 0; flag; i++){
flag  = 0;
  for(int j = n-1; j > i; j--){
    if(a[j-1] > a[j]){
      swap(a[j],a[j-1]);
      sw++;
      flag = 1;
    }
  }  
}
return sw;
}

int main(){

int n;
cin >> n;
int a[n];
rep(i,n) cin >> a[i];

int ans = bSort(a,n);

rep(i,n){
  if(i > 0) cout << " ";
  cout << a[i];
}
cout << endl;
cout << ans << endl;

return 0;

}
