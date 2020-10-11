#include<stdio.h>
int main(){
  int a,A[100],n,i,count=0,arr=101,arr2,arr3;/*arrは最小の値、arr2は交換、arr3は最小の場所*/
  scanf("%d",&a);
  for(n=0;n<a;n++){
    scanf("%d",&A[n]);
  }
  for(i=0;i<a-1;i++){
    arr=A[i];
 for(n=i;n<a;n++){
   if(A[n]<arr){
     arr=A[n];
     arr3=n;
}
 }
   if(A[i]!=arr){
     arr2=A[i];
   A[i]=arr;
   A[arr3]=arr2;
   count++;
  }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}
