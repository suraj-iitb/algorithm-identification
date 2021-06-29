#include<stdio.h>
#include<stdlib.h>

#define N 100000
#define Q 50000

int binaly(int);

int s[N],n;

//???????????¢??°
int main(void){

  //??????????????°?????£?¨?
  int i,q,count=0;
  int t;

 
  scanf("%d",&n);
  if(n>N) exit(1);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  
  scanf("%d",&q);
  if(q>Q) exit(2);  
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binaly(t)) count++;
  }

  
  printf("%d\n",count);
  return 0;
}


int binaly(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==key) return 1;
    else if(s[mid]<key) left=mid+1;
    else right=mid;
  }
  return 0;
}
