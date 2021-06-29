#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using ll = long long;
// using P = pair<int, int>;



int bubbleSort(int nums[],int n){
  bool flag = 1;
  int ans = 0;
  while(flag){
    flag = 0;
    for(int i = n-1; i > 0; i--){
      if(nums[i] < nums[i-1]){
        swap(nums[i],nums[i-1]);
        flag = 1;
        ans++;
      }
    }
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  int nums[n];
  rep(i,n) cin >> nums[i];
  int cnt = bubbleSort(nums,n);
  rep(i,n){
    if(i > 0) cout << " ";
    cout << nums[i];
  }
  cout << endl;
  cout << cnt << endl;
}
