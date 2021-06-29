#include<stdio.h>
#define N 10000
int main(){
  int i,j,count = 0,count1 = 0,count2 = 0,n,q,S[N],T[N],h,k;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }

  for(i = 0;i < q;i++){
    for(j = 0;j < n;j++){
      if(T[i] == S[j]){
	count1 = 1;
	count++;
      }
      if(count1 == 1){break;}
    }
    count1 = 0;
  }
	  printf("%d\n",count);

  return 0;
}
