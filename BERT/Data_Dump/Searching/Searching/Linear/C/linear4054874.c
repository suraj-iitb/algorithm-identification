#include<stdio.h>
#define MAX 10000

int Lis(int *,int,int);

int main() {

  int num[MAX];
  int n,m,i,key,count=0;

  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&num[i]);

  scanf("%d",&m);
  for(i=0;i<m;i++) {
    scanf("%d",&key);
    if( (Lis(num,n,key)) == 1 ) count++;
  }

  printf("%d\n",count);

  return 0;

}

int Lis(int *num,int n,int key) {

  int i=0;
  num[n] = key;

  while( num[i] != key) i++;

  if(i>=n) return 0;
  else return 1;

}
