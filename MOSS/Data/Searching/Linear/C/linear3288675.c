#include<stdio.h>

int search(int *,int,int);

int main(){
  int i,n,A[10000+1],b,x,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  scanf("%d",&b);
for(i=0;i<b;i++){
  scanf("%d",&x);
  if(search(A,n,x))sum++;
 }
 printf("%d\n",sum);

 return 0;
}

int search(int A[], int n, int x){
  int i=0;
  A[n]=x;
  while(A[i]!=x) i++;
  return i!=n;
}

