#include<stdio.h>
#define N 100
 
int main(){
  int numbers[N];
  int i,j,n,temp,c;
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&numbers[i]);
   
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(numbers[j]<numbers[j-1]){
    temp=numbers[j];
    numbers[j]=numbers[j-1];
    numbers[j-1]=temp;
    c=c + 1;
      }
    }
  }
 
   for(i=0;i<n-1;i++){
     printf("%d ",numbers[i]);
 
    
    }
 
   printf("%d\n",numbers[i]);
  printf("%d\n",c);
 
 
  return 0;
}



