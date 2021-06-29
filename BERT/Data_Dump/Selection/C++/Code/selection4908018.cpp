#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using ll = long long;
// using P = pair<int, int>;

int selectionSort(int nums[],int n){
  int cnt=0;
  for(int i = 0; i < n; i++){//未ソートの部分の先頭を表す。
    int minj = i; //各ループの処理でi番目からn-1までの要素で最小のものの位置
    for(int j = i; j < n; j++){//未ソートの部分から最小値の市を探す
      if(nums[j] < nums[minj]){
        minj = j;
      }
    }
    if(i != minj)cnt++;
    swap(nums[i],nums[minj]);
  }
 return cnt;
}

int main(){
  int n;
  cin >> n;
  int nums[n];
  rep(i,n) cin >> nums[i];
  int cnt = selectionSort(nums,n);
  rep(i,n){
    if(i > 0) cout << " ";
    cout << nums[i];
  }
  cout << endl;
  cout << cnt << endl;


}
