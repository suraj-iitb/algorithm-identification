#include<stdio.h>


int A[10000000];
int ans[10000000];
int c[10000000];



int main(){

  
  int number;


  
  scanf("%d",&number);


  


  int i;

  for(i=0;i<=number;i++){
    c[i]=0;
  }

  
  

  
  for(i=0;i<number;i++){
    scanf("%d",&A[i+1]);

    c[A[i+1]]++;

    
  }


  for(i=1;i<1000000;i++){
    c[i]=c[i]+c[i-1];

  }

  for(i=1;i<number+1;i++){
    ans[c[A[i]]]=A[i];
    c[A[i]]--;


   
  }
  
  
  for(i=1;i<=number;i++){
    if(i==number){printf("%d",ans[i]);}
    else{printf("%d ",ans[i]);}
  }

  printf("\n");

  
  return 0;
}



