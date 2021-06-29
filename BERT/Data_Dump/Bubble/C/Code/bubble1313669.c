#include<stdio.h>
 
int main(){
   
  int a[100],i,n,j,s,count=0;
   
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
    s = a[j-1];
    a[j-1] = a[j];
    a[j] = s;
    count++;
      }
    }
  }
   
  for(i=0;i<n;i++){
    printf("%d",a[i]);
      if(i==n-1){
    printf("\n");
    break;
      }
      printf(" ");
  }
   
  printf("%d\n",count);
  return 0;
}
