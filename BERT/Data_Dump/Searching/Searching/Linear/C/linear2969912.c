#include<stdio.h>
int search(int *,int,int);
int main(){
  int i,j,n,q,num=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    num += search(S,T[i],n);
  }
  printf("%d\n",num);
  return 0;
}

int search(int *S,int key,int n){
  int j;
  for(j=0;j<n;j++){
      if(key==S[j]){
	return 1;
      }
  }
  return 0;
}
