#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,k,key,hzi;
  int *hai;
  scanf("%d",&i);
  hai=(int *)malloc(sizeof(int));
  for(j=0;j<i;j++){
    scanf("%ld",&hai[j]);
  }
  for(j=0;j<i;j++){
     printf("%d",hai[j]);
     if(j!=i-1){
       printf(" ");
     }
  }
     printf("\n");
  for(j=1;j<i;j++){
    key=hai[j];
    hzi=j-1;
    while(hzi>=0 && hai[hzi]>=key){
      hai[hzi+1]=hai[hzi];
      hzi--;
    }
    hai[hzi+1]=key;
    for(k=0;k<i;k++){
     printf("%d",hai[k]);
     if(k!=i-1){
       printf(" ");
     }
    }
   printf("\n");
  }
  //free(hai);
return 0;
}


