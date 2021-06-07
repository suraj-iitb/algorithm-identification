#include<stdio.h>

int linerSearch(int*,int,int);

int main(){
  int n,S[10000];
  int q,T[10000];
  int i,j,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
    if(linerSearch(S,n,T[j])==2){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}
  
int linerSearch(int *s,int n,int key){
  int i=0;
  s[n]=key;
  while(s[i]!=key){
    i++;
  }
  if(i==n){
    return 1;
  }
  if(i<n)return 2;

}



