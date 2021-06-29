#include <iostream>
#include <algorithm>
using namespace std;

int merge_sort(int left,int right){
  if(left+1<right){
    int mid=(left+right) >> 1;
    return (merge_sort(left,mid)+merge_sort(mid,right)+right-left);
  }
  else{
    return (0);
  }
}


int main(){
  int x,n,S[500000];
  cin >> n;
  for(int i=0;i<n;i++) cin >> S[i];
  sort(S,S+n);

  x=merge_sort(0,n);

  for(int i=0;i<n;i++){
    if(i) cout << " ";
    cout << S[i];
  }
  cout << endl;
  cout << x << endl;
  return 0;
}


