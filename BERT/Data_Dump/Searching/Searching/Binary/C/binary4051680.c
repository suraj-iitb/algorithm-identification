#include<stdio.h>
void binary(int);
int n[100000],q[50000];
int right,left,mid,s,t,count=0;


int main(){
  int i;

  scanf("%d",&s);
  for(i=0;i<s;i++) scanf("%d",&n[i]);
  scanf("%d",&t);
  for(i=0;i<t;i++) scanf("%d",&q[i]);

  for(i=0;i<t;i++) binary(q[i]);

  printf("%d\n",count);
  return 0;
}
void binary(int key){
  left=0;
  right=s;
  mid=s/2;
  while(left<right){
    if(n[mid]<key){
      left=mid+1;
      mid=(left+right)/2;
    }else if(n[mid]>key){
      right=mid;
      mid=(left+right)/2;
    }else if(n[mid]==key){
      count++;
      return;
    }
  }
}

