#include<stdio.h>
int main(void){
int v,i,n,j,A[100];
int count = 0;
scanf("%d",&n);
for(i = 0;i < n;i++){
scanf("%d",&A[i]);}

for(j = 0;j < n;j++){
 for(i = n-1;i > j; i--){
  if(A[i]<A[i-1]){
  v = A[i];
  A[i] = A[i - 1];
  A[i - 1] = v;
  count++;
  }
 }
}
  for(i = 0;i < n;i++){
  if(i == n-1){
  printf("%d\n",A[i]);
}
  else {
  printf("%d ",A[i]);
}
}
  printf("%d\n",count);

 return 0;
}
