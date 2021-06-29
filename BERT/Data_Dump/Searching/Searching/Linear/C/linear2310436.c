#include <stdio.h>
#define N 10000
#define M 500

int ls(int s[],int n,int key);

int main(){
  int n,q,key;
  int s[N];
  int count=0;
  int i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(ls(s,n,key)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int ls(int s[],int n,int key){
  int i=0;
  s[n]=key;
  while(s[i]!=key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}
