#include<stdio.h>
#define N 10000
#define Q 500




int main(){
  int i, j, n, q, ans=0, S[N], T[Q];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
  scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
  scanf("%d",&T[i]);
  }

    for(j=0 ; j<q ; j++){
      i=0;
      S[n] = T[j];
      while(S[i] != T[j] ){
	i++;
      }
    if(i != n){
     
      ans++;
    }
    }

  printf("%d\n",ans);
  return 0;
}




