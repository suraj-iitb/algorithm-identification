#include<stdio.h>

#define N 10000

int linear(int *,int,int);

int main(){
  int pre,nex,i,cnt=0;
  int a[N],b[N];

  scanf("%d",&pre);
  for(i=0;i<pre;i++) scanf("%d",&a[i]);

  scanf("%d",&nex);
  for(i=0;i<nex;i++){
    scanf("%d",&b[i]);
    cnt += linear(a,b[i],pre);
  }

  printf("%d\n",cnt);

  return 0;
}

int linear(int *a,int b,int roop){
  int p=0,i;

  for(i=0;i<roop;i++){
    if(a[i]==b){
      p++;
      break;
    }
  }

  return p;
}
