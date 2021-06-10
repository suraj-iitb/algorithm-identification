#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  long long int INF=10000000000000;
  long long int i,j,k,dp[110][110],v,e,s,t,d;
  scanf("%lld %lld\n",&v,&e);
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      dp[i][j]=INF;
    }
  }
  for(i=0;i<e;i++){
    scanf("%lld %lld %lld\n",&s,&t,&d);
    dp[s][t]=min(dp[s][t],d);
  }
  for(i=0;i<v;i++){
    dp[i][i]=0;
  }
  for(k=0;k<v;k++){
    for(i=0;i<v;i++){
      for(j=0;j<v;j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  for(i=0;i<v;i++){
    if(dp[i][i]<0){
      printf("NEGATIVE CYCLE\n");
      return 0;
    }
  }
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      if(j==0){
        if(dp[i][j]>INF-20000000000){
          printf("INF");
        }
        else{
          printf("%lld",dp[i][j]);
        }
      }
      else{
        if(dp[i][j]>INF-20000000000){
          printf(" INF");
        }
        else{
          printf(" %lld",dp[i][j]);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
