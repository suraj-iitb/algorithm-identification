#include<stdio.h>

int hanbun(int);
int a,youso[100000];

int main(){
  int b,c,d,e,kazu=0;
  scanf("%d",&a);
  for(b=0;b<a;b++){
    scanf("%d",&youso[b]);
  }
  scanf("%d",&c);
  for(b=0;b<c;b++){
    scanf("%d",&d);
    e=hanbun(d);
    if(e)kazu++;
  }
  printf("%d\n",kazu);
  return 0;
}
int hanbun(int b)
{
  int right=a,left=0,mid;
  while(left<right){
    mid=(left+right)/2;
    if(youso[mid]==b) return 1;
    else if(b<youso[mid])right=mid;
    else left=mid+1;
  }
  return 0;
}
