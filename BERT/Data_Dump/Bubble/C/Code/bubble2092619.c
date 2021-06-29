#include <stdio.h>
int main(){
 int n,i,j,temp,count,num[100];
 
 scanf("%d",&n);
 for(i = 0;i < n;i++) scanf("%d",&num[i]);
 count=0;

 for(i = 0;i < n-1;i++){
  for(j = n-1; j > 0; j--){
   if(num[j]<num[j-1]){
    temp = num[j];
    num[j] = num[j-1];
    num[j-1] = temp;
    count++;
 }
 }
 }
 
 for(i = 0;i < n-1;i++){
 printf("%d ",num[i]);
 }
 printf("%d",num[n-1]);
 printf("\n%d\n",count);
 
 return 0;
}
