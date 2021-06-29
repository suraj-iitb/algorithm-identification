#include<stdio.h>
#define N 10000
#define TRUE 1
#define FALSE 0

int a[N],n,key;

int search(){
  int i=0;
  a[n]=key;
  while(a[i]!=key){
    i++;
    if(i==n) return FALSE;   
  }
  return TRUE;
}

int main(){
  int q,i,sum=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search()==TRUE) sum++;
  }
  
  printf("%d\n",sum);
  
  return 0;
}

