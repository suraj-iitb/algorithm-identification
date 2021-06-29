#include <stdio.h>

int binary(int,int,int*);


int main(void){
  int i,j;
  int count = 0;
  int S_num;
  int T_num;
  int S[100000],T[50000];

  scanf("%d",&S_num);
  for(i = 0; i < S_num; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&T_num);
  for(i = 0; i < T_num; i++){
    scanf("%d",&T[i]);
    count += binary(S_num,T[i],S);
  }

  printf("%d\n",count);
}
int binary(int n,int key,int *S){
  int left=0,right=n,mid;
  
  while(left<right){
    mid=(left+right) /2;
    if (S[mid] == key)
      return 1;
    else if (key<S[mid])
      right = mid;
    else left = mid +1;

  }
  return 0;
}
      

