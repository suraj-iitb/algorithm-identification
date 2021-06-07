#include<stdio.h>
#define N 100000
#define M 50000
int main(void){
  int i,j,k,s_total,t_total,left,right,mid=0,count=0;
  int S[N],T[M];

  scanf("%d",&s_total);
  for(i=0;i<s_total;++i){
    scanf("%d",&S[i]);
  }

  scanf("%d",&t_total);
  for(j=0;j<t_total;++j){
    scanf("%d",&T[j]);
  }
  for(k=0;k<t_total;k++){
    left=0;
    right=s_total;
   while(left<right){
     mid=(left+right)/2;
      if(S[mid]==T[k]){
        count++;
        break;
      }
      else if(S[mid]>T[k]){
        right=mid;
      }
      else {
        left=mid+1;
      }
   }
  }
  printf("%d\n",count);
  return 0;
}


