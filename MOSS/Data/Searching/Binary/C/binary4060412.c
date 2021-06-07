#include<stdio.h>
#include<string.h>
int bins(int ,int *,int);





int main(){
  int n,q,i,c=0,j,S[1000000],T[1000000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf(" %d",&T[j]);
  }
  for(i=0;i<q;i++){
    c+=bins(n,S,T[i]);
  }
  printf("%d\n",c);
  return 0;
}
int bins(int n,int *S,int key){
  int left=0;
  int right,mid;
  right = n;
  while(left < right){
    mid=(left+right) /2;
    if(S[mid]==key) return 1;
    else if(key <S[mid]) right = mid;
    else left = mid+1;
      }
  return 0;
}

