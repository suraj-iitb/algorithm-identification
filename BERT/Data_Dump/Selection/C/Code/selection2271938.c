#include<stdio.h>
 
int main(){
  int n,i,j,flag=0;
  int A[100];
  int num,temp,count=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    num = i;
    for(j=i;j<n;j++){
      if(A[j]<A[num])
        num = j;
     }  
    if(i!=num){
      temp=A[i];    
      A[i]=A[num];
      A[num]=temp;
      count++;
      }
     }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%d ",A[i]);
      else printf("%d\n",A[i]);
    }
    printf("%d\n",count);  
 
    return 0;
   }
