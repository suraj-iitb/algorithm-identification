#include<stdio.h>
int main(){
  int N,a[100],num;
  int i,j,k;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  for(k=0;k<N;k++){
    printf("%d",a[k]);
    
    if(k<N-1)printf(" ");
  }
  printf("\n");

  for(i=1;i<N;i++){
    num=a[i];
    j=i-1;
    
    while(j>=0 && a[j]>num){
      a[j+1]=a[j];
      j--;
      a[j+1]=num;
    }
    for(k=0;k<N;k++){
      printf("%d",a[k]);
      
      if(k<N-1)printf(" ");
    }
    printf("\n");
  }
return 0;
}
