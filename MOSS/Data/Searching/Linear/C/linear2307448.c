#include <stdio.h>
#define N 10000
#define M 500
int main(){
  int a,b,kosuu=0,i,j;
  int suuretu[N],suuretu2[M];

  //ins
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&suuretu[i]);
  }
  scanf("%d",&b);
  for(j=0;j<b;j++){
    scanf("%d",&suuretu2[j]);
  }

  //search
  for(j=0;j<b;j++){
    for(i=0;i<a;i++){
      if(suuretu[i]==suuretu2[j]){
	kosuu++;
	break;
      }
    }
  }
  printf("%d\n",kosuu);  
  return 0;
}
    
