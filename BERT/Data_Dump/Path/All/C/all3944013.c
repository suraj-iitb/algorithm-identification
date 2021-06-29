//https://triple-four.hatenablog.com/entry/2019/04/02/143939
//https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75
//https://www.slideshare.net/hcpc_hokudai/shortest-path-50585527
//https://www.npca.jp/works/magazine/2014_1/
//AOJ本
//マクロを使えるように

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define INF pow(10,10)


int main(){
  int v,e;
  int s,t,d;
  cin >> v >> e;
  vector<vector<long long>> dp(v,vector<long long>(v,INF));
  for(int i=0;i<e;i++){
    cin >> s >> t >> d;
    dp[s][t]=d;
    //有向ならdp[t][s]=dも
    //多重辺がある場合はmin(dp[s][t],d)とする
  }
  for(int i=0;i<v;i++){
    dp[i][i]=0;
  }
  for(int k=0;k<v;k++){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
        //INFへ足し引き算してもINF
        //ここもっとうまくできそう？？
        if(dp[i][k]!=INF && dp[k][j]!=INF){
          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
      }
    }
  }
  //負の閉じた経路がある場合は、割り続けるたびにマイナスになってしまう
  //WF法が終わった時点で自分自身に戻ってくるのがマイナスになればそれは負の閉じた経路にその頂点が含まれていることになる
  int x=0;
  for(int i=0;i<v;i++){
    if(dp[i][i]<0){
      x=1;
      break;
    }
  }
  if(x==1){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
        if(dp[i][j]==INF){
          //INFで変わらない場合があるのを考慮し忘れていた
          cout << "INF";
        }else{
          cout << dp[i][j];
        }
        if(j==v-1){
          cout << endl;
        }else{
          cout << " ";
        }
      }
    }
  }
}

