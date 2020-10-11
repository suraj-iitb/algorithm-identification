#include<stdio.h>
#define N 1000

int main(){
  int gyou=0;
  int retu[N];
  int temp=0;
  int i=0,j=0,k=0;
  
  scanf("%d",&gyou);
  
  for(i=0;i<gyou;i++){
    scanf("%d",&retu[i]);
  }

  for(i=0;i<gyou-1;i++){
    printf("%d ",retu[i]);
  }
  printf("%d\n",retu[gyou-1]);
  
  for(i=1;i<gyou;i++){
    temp=retu[i];
    j=i-1;
    while((j>=0) && (retu[j]>temp)){
      retu[j+1]=retu[j];
      j--;
      retu[j+1]=temp;
    }
    for(k=0;k<gyou-1;k++){
      printf("%d ",retu[k]);
    }
    printf("%d\n",retu[gyou-1]);
  }
  return 0;
}

