//二分探索

#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n,q,work;
  int *S;
  int i;
  int left=0,right,cnt=0;

  scanf("%d",&n);

  right=n;

  S=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&work);
    while(1){
      if(left==right) break;

      if(S[(left+right)/2]==work){
	cnt++;
	break;
      }

      if(S[(left+right)/2]>work) right=(left+right)/2;

      if(S[(left+right)/2]<work) left=(left+right)/2+1;
    }
    left=0;
    right=n;
  }

  printf("%d\n",cnt);

  free(S);

  return 0;
}
