#include <stdio.h>
int main(){
 int i,j,n,temp,min,count=0;
 int num[100];
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",&num[i]);

 for(i=0;i<n;i++){
  min=i;
  for(j=i;j<n;j++){
   if(num[min]>num[j]) min=j;
  }
  if(i!=min){
  temp=num[min];
  num[min]=num[i];
  num[i]=temp;
  count++;
  }
 }
 for(i=0;i<n-1;i++)printf("%d ",num[i]);
 printf("%d\n",num[n-1]);
 printf("%d\n",count);
 return 0;
}
