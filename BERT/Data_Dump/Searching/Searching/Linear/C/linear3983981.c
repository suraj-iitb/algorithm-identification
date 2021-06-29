#include <stdio.h>
#include <math.h>

int main(){
  int v,r,i,j,x;
  scanf("%d",&v);

  int a[v],cnt=0;
  for(i=0; i<v; i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&r);

  for(i=0; i<r; i++) {

    scanf("%d",&x);

    for(j=0; j<v; j++){
      if(a[j]==x){
	    cnt++;
	    break;
      }
    }
  }
  
  printf("%d\n",cnt);
  
  return 0;
}


