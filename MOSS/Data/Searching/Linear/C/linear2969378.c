#include<stdio.h>
#include<stdlib.h>
int linearsearch(int*,int,int);
int main(){
  int i=0,q,k,cnt=0;
  int n;
  int *t,*s;
  scanf("%d",&n);
  s=(int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  t=(int *)malloc(q * sizeof(int));
   for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
  for(i=0;i<q;i++){
    k=linearsearch(s,t[i],n);
    if(k==1)cnt++;
  }
  printf("%d\n",cnt);
  free(t);
  free(s);
  return 0;
}
int linearsearch(int s[],int key,int n){
  int i=0;
  while(s[i]!=key){
    i++;
    if(i==n)return 0;
  }
  return 1;
}

