#include<stdio.h>

int main(){
  int i,j,k,l,n,v;
  scanf("%d",&n);
  int data[n];
  /*配列dataに数値を格納*/
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  for(i=0;i<n;i++){
    printf("%d",data[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  
  for(i=1;i<n;i++){
    v=data[i];
    j=i-1;
    while(j>=0&&data[j]>v){
      data[j+1]=data[j];
      j--;
    }
    data[j+1]=v;
 
    for(k=0;k<n;k++){
      printf("%d",data[k]);
      if(k<n-1)printf(" ");
    }
    printf("\n");
 
  }
 

  return 0;

}

