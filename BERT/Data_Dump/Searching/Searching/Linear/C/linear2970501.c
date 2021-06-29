#include <stdio.h>
#define N 10000

int Linearsearch(int x[],int n,int key){
  int i=0;
  x[n] = key;
  while(x[i] != key) i++;
  return  i != n;
}

int main(){
  int i,n,x[N+1],q,key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)  scanf("%d",&x[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Linearsearch(x,n,key)) count++;
  }

  printf("%d\n",count);
  return 0;
}

