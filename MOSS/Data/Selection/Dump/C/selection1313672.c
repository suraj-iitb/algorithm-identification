#include<stdio.h>
 
int main(){
   
  int a[100],i,n,j,minj,s,count=0;
   
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
    minj = j;
      }
    }
    if(a[i]>a[minj]){
    s = a[i];
    a[i] = a[minj];
    a[minj] = s;
    count++;
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
