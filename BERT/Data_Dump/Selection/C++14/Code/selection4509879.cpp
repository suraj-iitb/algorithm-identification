#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 1; j <= (int)(m); j++)

int seleSort(int a[], int n){
int sw = 0;

rep(i,n){
  int minj = i;
  bool change = 0;
  for(int j = i; j<n; j++){
    if(a[j]<a[minj]){
    minj=j;
    change = 1;
    }
}
if(change){
  swap(a[i],a[minj]);
  sw++;
}
}
return sw;
}

int main(){

int n;
cin >> n;
int a[n];
rep(i,n) cin >> a[i];

int ans = seleSort(a,n);

rep(i,n){
  if(i > 0) cout << " ";
  cout << a[i];
}
cout << endl;
cout << ans << endl;

return 0;

}
