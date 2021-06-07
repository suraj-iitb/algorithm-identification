#include <stdio.h>
#include <math.h>

int main(){
  int v,r,i,j,x;
  scanf("%d",&v);

  int a[v],cnt=0;
  for(i=0; i<v; i++)
  {
    scanf("%d",&a[i]);
  }

  scanf("%d",&r);
  for(i=0; i<r; i++) {

    scanf("%d",&x);
    int w=v+1,l=-1;

    while(l+1!=w){

      int r=(l+w)/2;
      if(a[r]==x){
	     cnt++;
	     break;
      }
      if(a[r]<x){
      l=r;
      }
      else{
      w=r;
      }
    }
  }
  printf("%d\n",cnt);
  
  return 0;
}

