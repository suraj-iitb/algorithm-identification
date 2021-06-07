#include<stdio.h>
#define N 10002
#define TRUE 1
#define FALSE 0

int search(int *a, int n, int key){
  int i;
  a[n]=key;

  while(a[i]!=key){
    i++;
    if(i==n) return FALSE;
  }

  return TRUE;
}

int main(){
  int q,i,sum=0,a[N],n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(a,n,key)==TRUE) sum++;
  }

  printf("%d\n",sum);

  return 0;
}
