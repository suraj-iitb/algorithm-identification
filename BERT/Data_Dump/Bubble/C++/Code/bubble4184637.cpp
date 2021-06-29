#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int bubbleSort(vector <int> &a,int N){
  int sw = 0;

  //bubblesortの終了は値の移動が’行われない時である
  bool flag = 1; //値の移動があるかないかのflag

  //flagが立たない限り、一番小さい値をvectorの右に移動 。iはsortする回数
  for (int i =0; flag ; i++){
    flag = 0;
    for (int j = N-1;j>=i+1;j--){
      if(a.at(j)<a.at(j-1)){//もし、右の値が左の値より小さいなら、
        swap(a.at(j),a.at(j-1));//交換
        flag = 1;//移動を検知するflagを立てる
        sw++;
     }
   }

  }
  return sw;
}

int main(){


  int  n,sw;
  cin >>n;
  vector <int> a(100);
  rep(i,n) cin>>a.at(i);


  sw = bubbleSort(a,n);
  rep(i,n){
    if(i)cout<<" ";//ゼロ以外で出力
    cout<<a.at(i);
  }
  cout <<endl;
  cout <<sw <<endl;

  return 0;

}

