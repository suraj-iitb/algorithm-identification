#include<stdio.h>
#define N 100000
#define Q 50000

int main(){

  int i,j,x,y,b;
  int s[N],t[Q],a=0,mid,left,right;

  scanf("%d",&x);

  for(i=0;i<x;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&y);

  for(j=0;j<y;j++){
    scanf("%d",&t[j]);
  }


  for(b=0;b<y;b++){

  left=0;
  right=x;

  while(left<right){ 
    mid=(left+right)/2;
  if(s[mid]==t[b]){
    a++;
    break;
  }
  else if(t[b]<s[mid])
    right=mid;
  else if(t[b]>s[mid])
    left=mid+1;
  }
  }

  printf("%d\n",a);
  return 0;
}
