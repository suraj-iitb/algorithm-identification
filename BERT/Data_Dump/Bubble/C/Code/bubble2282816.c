#include <stdio.h>
		    
int main(){
  int handan=1,a,i,j,k,kaisuu=0;
  int N,suuretu[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&suuretu[i]);
  }
  
  while(handan){
    handan=0;
    for(j=N-1;j>=1;j--){
      if(suuretu[j]<suuretu[j-1]){
	k=suuretu[j];
	suuretu[j]=suuretu[j-1];
	suuretu[j-1]=k;
	handan=1;
	kaisuu++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",suuretu[i]);
  }
  printf("%d\n",suuretu[N-1]);
  printf("%d\n",kaisuu);
  return 0;
}
