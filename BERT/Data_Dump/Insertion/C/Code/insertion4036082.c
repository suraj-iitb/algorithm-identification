#include <stdio.h>
int main(){
  int N_tw,V_tw,i,j,k;
  scanf("%d",&N_tw);
  int A_tw[N_tw];
  for(i=0;i<N_tw;i++){
    scanf("%d",&A_tw[i]);
    
  }
  for(i=0;i<N_tw;i++){
    V_tw=A_tw[i];
    j=i-1;
    while(j>=0&&A_tw[j]>V_tw){
      A_tw[j+1]=A_tw[j];
      j--;
    }
    A_tw[j+1]=V_tw;
    for(k=0;k<N_tw;k++){
      if(1<=k&&k<N_tw)printf(" ");
      printf("%d",A_tw[k]);
      
    }
    printf("\n");
  }
  return 0;
}
  
    

