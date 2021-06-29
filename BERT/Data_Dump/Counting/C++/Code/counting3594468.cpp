#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

int main(void){
  int n,a,i;
  int cnt[10001]={};

  cin>>n;

  for(i=0;i<n;i++){
    cin>>a;
    cnt[a]++;
  }

  for(i=0;i<10001;i++){
    while(cnt[i]>1){
      printf("%d ",i);
      cnt[i]--;
      n--;
    }
    if(cnt[i]){
      printf("%d",i);
      if(n==1){
        printf("\n");
        return 0;
      }
      else{
        printf(" ");
        n--;
      }
    }
  }

	return 0;
}
