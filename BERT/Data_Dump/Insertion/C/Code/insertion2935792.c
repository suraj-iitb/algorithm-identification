#include <stdio.h>
int main(){
  int i,num,key,j,k;
  
  scanf("%d",&num);
  
  int a[num];
  
  for(i = 0 ; i<num ;i++){
    scanf("%d",&a[i]);
  }
  
  for(i = 0 ; i<num ;i++){
      if(i == num-1) printf("%d\n",a[i]);
      else    printf("%d ",a[i]);
  }
  for(i = 1 ; i<=num-1 ;i++){
    key = a[i];
    j = i-1;
    while(j>=0 && a[j] >key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
    for(k = 0 ; k<num ;k++){
      if(k == num-1) printf("%d\n",a[k]);
      else  printf("%d ",a[k]);
    }
  }
  return 0;
}
  
   

