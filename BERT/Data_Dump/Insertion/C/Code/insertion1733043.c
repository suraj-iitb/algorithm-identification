#include<stdio.h>

int main(){
  int num[1000];
  int N;
  int i, j, k, v, len;  
  
  scanf("%d",&N);
  len=N;
    
  for( i = 0; i < len; i++){
    scanf("%d", &num[i]);
  }
  for(k = 0; k < len ; k++){
      if(k != len-1)printf("%d ",num[k]);
      else printf("%d\n",num[k]);
    }
  
  for( i = 1; i < len ; i++){
    v = num[i];
    j = i-1;
    while(j >= 0 && num[j]>v){
      num[j+1] = num[j];
      j--;
    }
    num[j+1] = v;
    for(k = 0; k < len ; k++){
      if(k != len-1)printf("%d ",num[k]);
      else printf("%d\n",num[k]);
    }

  }
  return 0;

}
