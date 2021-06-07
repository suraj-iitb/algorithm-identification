#include<stdio.h>
#define N 10000

int main(){
  int point1,point2,i,j,n,line1[N],line2[N];
  
  scanf("%d",&point1);
  for(i=0 ; i<point1 ; i++){
    scanf("%d",&line1[i]);
  }
  
  scanf("%d",&point2);

  for(i=0 ; i<point2 ; i++){
    scanf("%d",&line2[i]);
  }
  n=0;
  for(i=0 ; i<point2 ; i++){
    for(j=0 ; j<point1 ; j++){
      if(line1[j]==line2[i]){
	n++;
	break;
      }
    }
  }
  printf("%d\n",n);
  
  return 0;
}

