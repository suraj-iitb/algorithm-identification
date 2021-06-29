#include<stdio.h>

#define N 100 //max data number


int main(){
  int cnt, num[N], i, j, key;
  

  //input number of article
  scanf("%d",&cnt);

  
  //input data
  for(i=0;i<cnt;i++) scanf("%d",&num[i]);

  
  //sort
  for(i=1;i<cnt;i++){
    //print data
    for(key=0;key<cnt-1;key++) printf("%d ",num[key]);
    printf("%d\n",num[key]);

    
    key=num[i];
    j=i-1;

    while(j>=0 && num[j] > key){
      num[j+1]=num[j];
      j--;
    }
    num[j+1]=key;
  }
  
  //print data
  for(key=0;key<cnt-1;key++) printf("%d ",num[key]);
  printf("%d\n",num[key]);
  
  return 0;
}


