#include<stdio.h>
#define N 101
  int main(){
  int lengh;
  int A[N],i,j,key,count=0;
  scanf("%d",&lengh); 
for(i=1;i<=lengh;i++){
    scanf("%d",&A[i]);}
  for(i=1;i<=lengh;i++){
    for(j=lengh;j>=i+1;j--){
      if(A[j]<A[j-1]){
    key=A[j];
    A[j]=A[j-1];
    A[j-1]=key;
    count++;}}}
  for(i=1;i<=lengh;i++){
if(i==lengh){
printf("%d\n",A[i]); 
	break;
}
 printf("%d ",A[i]);
}
   
printf("%d\n",count);
  return 0;}
