//線型探索

#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n,q,cnt=0,work;
  int *S;
  int i,j;

  scanf("%d",&n);

  S=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&work);
    for(j=0;j<n;j++){
      if(S[j]==work){
	cnt++;
	break;
      }
    }
  }

  printf("%d\n",cnt);

  free(S);
}
