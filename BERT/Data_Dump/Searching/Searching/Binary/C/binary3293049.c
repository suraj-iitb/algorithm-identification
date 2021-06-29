#include<stdio.h>
#define N 100000
#define Q 50000

int binary(int ,int *,int );

int main(){
  int right,s[N],t[Q],x,y,i,k=0,target;

  scanf("%d",&x);
  for(i=0;i<x;i++)
    scanf("%d",&s[i]);
  scanf("%d",&y);
  for(i=0;i<y;i++)
    scanf("%d",&t[i]);
  right=x;
  
  for(i=0;i<y;i++){
    target=t[i];
    if((binary(target,s,right))==1){
      k++;
    }
  }
  printf("%d\n",k);
  return 0;
}
int binary(int target,int *s,int right){
  int left=0,mid;
  while(left<right){
    mid=(left+right)/2;
    if(target==s[mid])
      return 1;
    if(target>s[mid])
      left=mid+1;
    if(target<s[mid])
      right=mid;
  }
  return 0;
}

